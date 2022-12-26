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
    InitIO("outofplace");

    int n;
    std::cin >> n; 
    std::vector<int> Heights(n);
    for(int& x : Heights) {
        std::cin >> x;
    }

    // Do a basic bubble sort and count the swaps while we are at it
    int NumSwaps = 0;
    bool Change = true;
    while(Change) { 
        Change = false;
        for(int i = 1; i < n; i++) {
            int* Curr = &Heights[i];
            int* Prev = Curr - 1;
            if(*Prev > *Curr) {
                int Orig = *Prev;
                for(int im2 = i - 2; im2 >= 0 && Heights[im2] == Orig; im2--) {
                    Prev--;
                }
                Orig = *Curr;
                for(int ip1 = i + 1; ip1 < n && Heights[ip1] == Orig; ip1++) {
                    Curr++;
                }
                std::swap(*Prev, *Curr);
                NumSwaps++;
                Change = true;
            }
        }
    }

    std::cout << NumSwaps << '\n';

    return 0;
}

/*

 bool Found = false;
    int Pos, Val;

    for(int i = 1; i < n; i++) {
        int Prev = Heights[i - 1], Curr = Heights[i];
        if(Curr < Prev) {
            Found = true;
            Pos = i;
            Val = Curr;
            break;
        }
    }

    if(!Found) {
        std::cout << "0\n";
        return 0;
    }

    for(int i = 0; i < n; i++) {
        if(i == Pos) {
            continue;
        } else {
            if(Heights[i] >= Val) {
                int MoveTo = i;
                int NumSwaps = std::abs(i - Pos) - 1;
                std::cout << NumSwaps << '\n';
                return 0;
            } 
        }
    }
*/