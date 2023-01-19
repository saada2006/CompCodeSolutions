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

#include <utility>
#include <vector>
#include <algorithm>

int main() {
    InitIO("cowqueue");

    int n;
    std::cin >> n;

    std::vector<std::pair<int, int>> Times(n);
    for(auto& T : Times) {
        std::cin >> T.first >> T.second;
    }
    std::sort(Times.begin(), Times.end());

    int CurrentTime = 0;
    for(const auto& T : Times) {
        if(T.first > CurrentTime) {
            CurrentTime = T.first + T.second; 
        } else {
            CurrentTime += T.second;
        }
    } 

    std::cout << CurrentTime << '\n';

    return 0;
}