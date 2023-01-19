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
We can assume what the first value of a could be (in order (0...n - 1) + 1)
Then we can calculate the rest of a and see whether it or b makes sense
Then we can check for repititions by sorting
*/

#include <vector>
#include <algorithm>

int main() {
    InitIO("photo");

    int n;
    std::cin >> n;

    std::vector<int> b(n - 1);
    for(int& bi : b) {
        std::cin >> bi;
    }

    std::vector<int> a;
    a.reserve(n);
    
    return 0;
}
