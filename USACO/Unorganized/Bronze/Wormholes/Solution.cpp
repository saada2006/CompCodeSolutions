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

struct Coordinate {
    int x, y;
    bool operator<(const Coordinate& Other) {
        if(y == Other.y) {
            return x < Other.x;
        } else {
            return y < Other.y;
        }
    }
};

/*
Plan:
Basically we assume bessie starts dx right before a wormhole, and we try to pair that wormhole with other wormholes and we will mark those wormholes
For the next wormhole we see if the next wormhole in a sorted list of wormholes is actually on the same y-level and it's marked already to increment the counter
To make the counter only of distinct pairs, we divide by 2 since wormholes can be switched and then 6! since there can be multiple permutations 
*/

int main() {
    
}