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
#include <utility>

// For each node keep track of its current seed type and connections

int main() {
    InitIO("revegetate");

    int n, m;
    std::cin >> n >> m;
    std::vector<std::pair<int, std::vector<int>>> Nodes(n);
    for(int i = 0; i < n; i++) {
        Nodes[i].first = 0;
    }
    for(int i = 0; i < m; i++) {
        int Connection[2];
        std::cin >> Connection[0] >> Connection[1];
        Connection[0]--; Connection[1]--;
        Nodes[Connection[0]].second.push_back(Connection[1]);
        Nodes[Connection[1]].second.push_back(Connection[0]);
    }

    for(auto& Pasture : Nodes) {
        bool Taken[4] {false, false, false, false};
        for(int Connection : Pasture.second) {
            int Seed = Nodes[Connection].first;
            if(Seed != 0) {
                Taken[Seed - 1] = true;
            }
        }
        for(int i = 0; i < 4; i++) {
            if(!Taken[i]) {
                Pasture.first = i + 1;
                std::cout << Pasture.first;
                break;
            }
        }
    }

    return 0;
}