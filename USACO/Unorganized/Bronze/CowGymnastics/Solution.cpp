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
#include <algorithm>

bool CheckRelativeRanking(const std::vector<int>& Rankings, int Cow0, int Cow1) {
    int Ranks[2];

    Ranks[0] = std::distance(Rankings.begin(), std::find(Rankings.begin(), Rankings.end(), Cow0));
    Ranks[1] = std::distance(Rankings.begin(), std::find(Rankings.begin(), Rankings.end(), Cow1));

    return (Ranks[0] > Ranks[1]);
}

bool CheckConsistency(const std::vector<std::vector<int>>& FullRankings, int Cow0, int Cow1) {
    bool ExpectedResult = CheckRelativeRanking(FullRankings.front(), Cow0, Cow1);

    for(const auto& Ranking : FullRankings) {
        bool CurrentResult = CheckRelativeRanking(Ranking, Cow0, Cow1);
        if(CurrentResult != ExpectedResult) {
            return false;
        }
    }

    return true;
}

int main() {
    InitIO("gymnastics");

    int k, n;
    std::cin >> k >> n;

    std::vector<std::vector<int>> FullRankings(k);
    for(auto& Ranking : FullRankings) {
        Ranking.resize(n);
        for(auto& Rank : Ranking) {
            std::cin >> Rank;
        }
    }

    int Pairs = 0;

    for(int Cow0 = 1; Cow0 <= n; Cow0++) {
        for(int Cow1 = Cow0 + 1; Cow1 <= n; Cow1++) {
            if(CheckConsistency(FullRankings, Cow0, Cow1)) {
                Pairs++;
            }
        }
    }

    std::cout << Pairs << '\n';
    return 0;
}