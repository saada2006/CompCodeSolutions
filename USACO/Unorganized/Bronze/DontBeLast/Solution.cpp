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

#include <unordered_map>
#include <map>
#include <string>
#include <algorithm>

std::map<int, std::string>::iterator GetIter(std::map<int, std::string>& Map, int Index) {
    auto Iter = Map.begin();
    std::advance(Iter, Index);
    return Iter;
}

int main() {
    InitIO("notlast");

    int n;
    std::cin >> n;
    std::unordered_map<std::string, int> MilkProductionByCow;
    for(int i = 0; i < n; i++) {
        std::string Cow; 
        int MilkIncrease;
        std::cin >> Cow >> MilkIncrease;
        MilkProductionByCow[Cow] += MilkIncrease;
    }

    std::multimap<int, std::string> ReverseMapping;
    for(const auto& P : MilkProductionByCow) {
        ReverseMapping.emplace(P.second, P.first);
    }

    int M = 0;
    if(ReverseMapping.size() == 7) {
        M = ReverseMapping.begin()->first;
    }

    for(auto Iter = ReverseMapping.begin(); Iter != ReverseMapping.end(); Iter++) {
        if(Iter->first > M) {
            auto Next = Iter;
            std::advance(Next, 1);
            if(Iter->first == Next->first) {
                std::cout << "Tie\n";
            } else {
                std::cout << Iter->second << '\n';
            }
            return 0;
        }
    }
    std::cout << "Tie\n";

}