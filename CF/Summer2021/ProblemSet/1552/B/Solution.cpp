#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>

struct Athlete {
    int Score[5];

    int& operator[](int idx) {
        return Score[idx];
    }

    // Check if *this is better than Other
    bool Superior(const Athlete& Other) const {
        int c = 0;
        for(int i = 0; i < 5; i++) {
            if(Score[i] < Other.Score[i]) {
                c++;
            }
        }
        return (c >= 3);
    }
};

void solve() {
    int n;
    std::cin >> n;

    std::vector<Athlete> Runners(n);
    for(Athlete& Athl : Runners) {
        for(int i = 0; i < 5; i++) {
            std::cin >> Athl[i];
        }
    }

    int BestAthlIdx = 0;
    for(int i = 1; i < n; i++) {
        if(Runners[i].Superior(Runners[BestAthlIdx])) {
            BestAthlIdx = i;
        }
    }

    for(int i = 1; i < n; i++) {
        int j = (i + BestAthlIdx) % n;
        if(Runners[j].Superior(Runners[BestAthlIdx])) {
            std::cout << -1 << '\n';
            return;
        }
    }

    std::cout << BestAthlIdx + 1 << '\n';
}

int main() {
    int t;
    std::cin >> t;

    while(t--)
        solve();

    return 0;
}