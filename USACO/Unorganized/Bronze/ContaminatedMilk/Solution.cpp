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

/*
Plan: build list of milk drunk by people up to t
Then find a common element of milks drunk 
Then count the number of unique drinkers of the bad milk
*/

#include <vector>
#include <utility>
#include <algorithm>
#include <set>
#include <iterator>

int main() {
    InitIO("badmilk");

    int n, m, d, s;
    std::cin >> n >> m >> d >> s;

    std::vector<std::vector<std::pair<int, int>>> MilkDrunk(n);
    for(int i = 0; i < d; i++) {
        int Person, Milk, Time;
        std::cin >> Person >> Milk >> Time;
        Person--;
        MilkDrunk[Person].emplace_back(Milk, Time);
    }

    std::vector<std::set<int>> PossibleBadMilks(n);
    std::set<int> TotalBadMilks, BadMilkIntersection;
    for(int i = 0; i < s; i++) {
        int Person, Time;
        std::cin >> Person >> Time;
        Person--;
        
        // Search through milks drank before Time
        for(const auto& Milk : MilkDrunk[Person]) {
            if(Milk.second < Time) {
                PossibleBadMilks[Person].insert(Milk.first);
                TotalBadMilks.insert(Milk.first);
            }
        }
    }

    
    for(const auto& MilkSet : PossibleBadMilks) {
        if(MilkSet.empty()) {
            continue;
        }
        std::set_intersection(TotalBadMilks.begin(), TotalBadMilks.end(), MilkSet.begin(), MilkSet.end(), std::inserter(BadMilkIntersection, BadMilkIntersection.begin()));
        TotalBadMilks = BadMilkIntersection;
        BadMilkIntersection.clear();
    }

    int BadMilk = *TotalBadMilks.begin();

    int MedicineDoses = 0;
    for(const auto& MilkSet : MilkDrunk) {
        for(const auto& Milk : MilkSet) {
            if(Milk.first == BadMilk) {
                MedicineDoses++;
                break;
            }
        }
    }
    std::cout << MedicineDoses << '\n';
    return 0;
    
}