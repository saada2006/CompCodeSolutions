// Copy paste for fast USACO file I/O redirection
#include <iostream>
#include <cstdio>
void InitIO(const char* FileName) {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    
    constexpr std::size_t BufferSize = 256;
    char StrBuf[BufferSize];

    StrBuf[0] = '\0';
    std::snprintf(StrBuf, BufferSize, "%s.in", FileName);
    freopen(StrBuf, "r", stdin);

    StrBuf[0] = '\0';
    std::snprintf(StrBuf, BufferSize, "%s.out", FileName);
    freopen(StrBuf, "w", stdout);    
}

#include <vector>
#include <utility>
#include <algorithm>

int GetCoveredTime(const std::vector<std::pair<int, int>>& Schedule, int Ignore) {
    int Coverage[2] { -1, -1};
    int Time = 0;
    int Max = Schedule.size();
    if(Ignore + 1 == Schedule.size()) {
        Max--;
    }
    for(int i = 0; i < Schedule.size(); i++) {
        if(i == Ignore) {
            continue;
        }

        // Does next time period start before current ends? 
        if(Schedule[i].first <= Coverage[1]) {
            Coverage[1] = std::max(Coverage[1], Schedule[i].second);
        } 
        
        if(Schedule[i].first > Coverage[1]) {
            Time += Coverage[1] - Coverage[0];
            Coverage[0] = Schedule[i].first;
            Coverage[1] = Schedule[i].second;
        }

        if(i + 1 == Max) {
            Time += Coverage[1] - Coverage[0];
        }
    }
    return Time;
}

int main() {
    InitIO("lifeguards");

    int n;
    std::cin >> n;

    std::vector<std::pair<int, int>> Schedule(n);
    for(auto& Timing : Schedule) {
        std::cin >> Timing.first >> Timing.second;
    }
    std::sort(Schedule.begin(), Schedule.end());

    int MaxTime = 0;
    for(int i = 0; i < n; i++) {
        MaxTime = std::max(MaxTime, GetCoveredTime(Schedule, i));
    }

    std::cout << MaxTime << '\n';
    return 0;
}