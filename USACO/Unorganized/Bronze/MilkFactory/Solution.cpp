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

void Search(const std::vector<std::vector<int>>& Connections, std::vector<int>& Found, int Current) {
    for(const int Neighbor : Connections[Current]) {
        Found.push_back(Neighbor);
        Search(Connections, Found, Neighbor);
    }
}

int main() {
    InitIO("factory");

    int n;
    std::cin >> n;
    std::vector<std::vector<int>> Walkways(n);
    for(int i = 1; i < n; i++) {
        int Connection[2];
        std::cin >> Connection[0] >> Connection[1];
        Connection[0]--; Connection[1]--;
        Walkways[Connection[1]].push_back(Connection[0]);
    }

    std::vector<int> FoundNodes;
    FoundNodes.reserve(n);
    for(int i = 0; i < n; i++) {
        FoundNodes.clear();
        Search(Walkways, FoundNodes, i);
        if(FoundNodes.size() + 1 == n) {
            std::cout << i + 1 << '\n';
            return 0;
        }
    }

    std::cout << "-1\n";
    return 0;
}