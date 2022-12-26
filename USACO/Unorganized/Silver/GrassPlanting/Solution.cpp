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

int main() {
    InitIO("planting");

    int n;
    std::cin >> n;

    if(n == 1) {
        std::cout << 1 << '\n';
        return 0;
    }

    std::vector<int> NumConnections(n);
    for(int i = 1; i < n; i++) {
        int Connections[2];
        std::cin >> Connections[0] >> Connections[1];
        Connections[0]--; Connections[1]--;
        NumConnections[Connections[0]]++;
        NumConnections[Connections[1]]++;
    }

    int MaxDegree = 0;
    for(const int Degree : NumConnections) {
        MaxDegree = std::max(MaxDegree, Degree);
    }

    std::cout << MaxDegree  + 1 << '\n';

    return 0;
}