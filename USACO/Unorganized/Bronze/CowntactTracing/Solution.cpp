// Copy paste for fast USACO file I/O redirection
#include <iostream>
#include <cstdio>
void InitIO(const char* FileName) {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    
    constexpr std::size_t BufferSize = 256;
    char StrBuf[BufferSize];

    StrBuf[0] = '\0';
    std::snprintf(StrBuf, BufferSize, "%s.in", FileName);
    std::freopen(StrBuf, "r", stdin);

    StrBuf[0] = '\0';
    std::snprintf(StrBuf, BufferSize, "%s.out", FileName);
    std::freopen(StrBuf, "w", stdout);    
}

#include <vector>
#include <algorithm>
#include <string>

struct ContagiousInteraction {
    int Time;
    int Cow[2];
    bool operator<(const ContagiousInteraction& Other) {return this->Time < Other.Time;}
    int& operator[](int Idx) {return Cow[Idx]; }
};

int main() {
    InitIO("tracing");

    int n, t;
    std::cin >> n >> t;

    std::string EndResStr;
    std::cin >> EndResStr;
    std::vector<bool> Infections;
    Infections.reserve(n);
    for(const char C : EndResStr) {
        Infections.push_back(C == '1');
    }

    std::vector<ContagiousInteraction> Interactions(t);
    for(auto& Interact : Interactions) {
        std::cin >> Interact.Time >> Interact[0] >> Interact[1];
        // Move to 0-indexing
        Interact[0]--;
        Interact[1]--;
    }
    std::sort(Interactions.begin(), Interactions.end());
    
    int K[3] {-2147483648, 2147483647, 0};
    for(int i = 0; i < n; i++) {
        if(!Infections[i]) {
            continue;
        }

        bool ValidStart = false;

        // J is supposed to be k but whatever
        for(int j = 0; j <= 250; j++) {
            std::vector<int> InfectionCounter(n);
            std::vector<bool> Simulation(n);
            Simulation[i] = true;

            // Loop through all interactions
            for(int k = 0; k < t; k++) {
                auto Interaction = Interactions[k];
                bool Write[2] {false, false};

                if(Simulation[Interaction[0]] && InfectionCounter[Interaction[0]] < j) {
                    InfectionCounter[Interaction[0]]++;
                    Write[1] = true;
                }
                if(Simulation[Interaction[1]] && InfectionCounter[Interaction[1]] < j) {
                    InfectionCounter[Interaction[1]]++;
                    Write[0] = true;
                }
                Simulation[Interaction[0]] = Simulation[Interaction[0]] | Write[0];
                Simulation[Interaction[1]] = Simulation[Interaction[1]] | Write[1];
            }

            bool ValidConfig = true;
            for(int k = 0; k < n; k++) {
                if(Infections[k] != Simulation[k]) {
                    ValidConfig = false;
                    break;
                }
            }
            ValidStart |= ValidConfig;

            if(ValidConfig) {
                if(j < 250) {
                    K[0] = std::max(K[0], j);
                } else {
                    K[0] = 2147483647;
                }
                K[1] = std::min(K[1], j);
            }
        }
        if(ValidStart) {
            K[2]++;
        }
    }
    std::cout << K[2] << ' ' << K[1] << ' ' << (K[0] != 2147483647 ? std::to_string(K[0]) : "Infinity") << '\n';
    return 0;
}

/*

std::vector<bool> SimulationInfections(n);
    std::vector<int>  InfectionCounter(n);
    int KMax = -2147483648;
    int KMin =  2147483647;
    for(int i = 0; i < n; i++) {
        if(!Infections[i]) {
            continue;
        }

        // Run simulation using cow_i as pat 0
        std::fill_n(SimulationInfections.begin(), n, false);
        std::fill_n(InfectionCounter.begin(), n, 0);
        SimulationInfections[i] = true;

        int CurrentMax =   2147483647;
        int CurrentMin =  -2147483648;
        // Step through interactions
        for(int j = 0; j < t; j++) {   
            ContagiousInteraction& CurrentInteraction = Interactions[j];

            // Does the infecter have enoguh infections remaining?
            if(InfectionCounter[j] < CurrentMin) {
                // Is the final cell actually infected?
                if(Infections[j]) {
                    SimulationInfections[j] = true; // Even if it was already infected before it still contributes to the k shakes
                    InfectionCounter[j]++; 
                } else {
                    // Set new lower bound
                    CurrentMin = std::max(CurrentMin, InfectionCounter[j]);
                }
            }
        }
    }

    return 0;
*/


/*
Plan: 
We can run a simulation for each cow being pat 0
We can calculate a lower bound on k by seeing if an interaction of infected and safe cows does not result in another infection
If k = t then k = inf for the upper bound, otherwise, we can take the max of all simulation runs

Running the simulation:
Initially, set one cow to '1' to make it infected 
Then, step through the chronological interactions and keep track of how many cows each cow has infected and how many total interactions
If an infected cow does not infect another cow we can set that as a lower bound for k
If no such interaction exists then the lower bound is the most cows infected by a single cow and the upper bound is inf

*/