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

/*
Go to edges of current range
Then check if the next one right after range is in range of outermost 
*/

int main() {
    InitIO("angry");

    int n;
    std::cin >> n;
    std::vector<int> Bales(n);
    for(int& x : Bales) {
        std::cin >> x;
    }
    std::sort(Bales.begin(), Bales.end());

    int MaxBales = -2147483648;
    for(int i = 0; i < n; i++) {
        int NumBales = 1;
        
        int Range = 0;
        int MaxRange = Bales[i];
        for(int j = i + 1; j < n; j++) {
            if(Bales[j] > MaxRange) {
                Range++;
                MaxRange = Bales[j - 1] + Range;
                if(Bales[j] <= MaxRange) {
                    NumBales++;
                } else {
                    break;
                }
            } else {
                NumBales++;
            }
        }

        Range = 0;
        MaxRange = Bales[i];
        for(int j = i - 1; j > -1; j--) {
            if(Bales[j] < MaxRange) {
                Range++;
                MaxRange = Bales[j + 1] - Range;
                if(Bales[j] >= MaxRange) {
                    NumBales++;
                } else {
                    break;
                }
            } else {
                NumBales++;
            }
        }
        MaxBales = std::max(MaxBales, NumBales);
    }

    std::cout << MaxBales << '\n';

    return 0;
}