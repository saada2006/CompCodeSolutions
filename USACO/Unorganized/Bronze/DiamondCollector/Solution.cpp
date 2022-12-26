#include <iostream>
#include <vector>
#include <algorithm>

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
    InitIO("diamond");

    int n, k;
    std::cin >> n >> k;

    std::vector<int> Diamonds(n);
    for(int& Size : Diamonds) {
        std::cin >> Size;
    }
    std::sort(Diamonds.begin(), Diamonds.end());

    int MaxDiamonds = 1;
    for(int Diamond0 = 0; Diamond0 < Diamonds.size(); Diamond0++) {
        for(int Diamond1 = Diamond0 + 1; Diamond1 < Diamonds.size(); Diamond1++) {
            int SizeDifference = Diamonds[Diamond1] - Diamonds[Diamond0];
            if(SizeDifference > k || Diamond1 + 1 == Diamonds.size()) {
                if(Diamond1 + 1 == Diamonds.size() && SizeDifference <= k) {
                    Diamond1++;
                }
                int CurrentDiamonds = Diamond1 - Diamond0;

                MaxDiamonds = std::max(MaxDiamonds, CurrentDiamonds);
                break;
            }
        }
    }

    std::cout << MaxDiamonds << '\n';
    return 0;
}