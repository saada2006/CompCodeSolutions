#include <iostream>

// Copy paste for fast USACO file I/O redirection
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

int main() {
    InitIO("pails");

    int x, y, m;
    std::cin >> x >> y >> m;

    int xt = 0;
    int max = 0;
    while(xt <= m) {
        int yt = 0;
        while(xt + yt <= m) {
            int sum = xt + yt;
            if(sum <= m && sum > max) {
                max = sum;
            }
            yt += y;
        }
        xt += x;
    }

    std::cout << max << '\n';
    return 0;
}