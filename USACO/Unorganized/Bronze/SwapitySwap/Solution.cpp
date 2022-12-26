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
    InitIO("swap");

    int n, k, A[2], B[2];

    std::cin >> n    >> k 
             >> A[0] >> A[1]
             >> B[0] >> B[1];

    // Why can't every agree on 0-indexing???
    A[0]--; //A[1]--;
    B[0]--; //B[1]--;

    std::vector<int> Original(n), Modified(n);
    for(int i = 0; i < n; i++) {
        Original[i] = Modified[i] = i + 1;
    }

    int NumLoops = 0;

    do {
        std::reverse(Modified.begin() + A[0], Modified.begin() + A[1]);
        std::reverse(Modified.begin() + B[0], Modified.begin() + B[1]);
        NumLoops++;
    } while(!std::equal(Original.begin(), Original.end(), Modified.begin(), Modified.end()));

    // [i][j] What node is at position i after j swaps? (every NumLoops (typically 6) swaps loop back around to starting positon)
    std::vector<int> Cycle(n * NumLoops); 
    for(int i = 0; i < n; i++) {
        Cycle[i] = i + 1;
    }

    for(int j = 1; j < NumLoops; j++) {
        int Base = j * n;
        std::copy_n(Cycle.begin() + Base - n, n, Cycle.begin() + Base);
        std::reverse(Cycle.begin() + Base + A[0], Cycle.begin() + Base + A[1]);
        std::reverse(Cycle.begin() + Base + B[0], Cycle.begin() + Base + B[1]);
    }

    int CycleBase = n * (k % NumLoops);
    for(auto Iter = Cycle.begin() + CycleBase; Iter != Cycle.begin() + CycleBase + n; Iter++) {
        std::cout << *Iter << '\n';
    }

    return 0;
}

/*

void prnt(int i, const std::vector<int>& vec) {
    std::cout << i << ":\t";
    for(const int x : vec) {
        std::cout << x << ' ';
    }
    std::cout << '\n';
}

int main() {
    InitIO("swap");

    std::vector<int> Test = {
        1, 2, 3, 4, 5, 6, 7, 8, 9,
    };

    int a1 = 1, a2 = 6;
    int b1 = 3, b2 = 9;

    prnt(0, Test);
    for(int i = 1 ; i <= 100; i++) {
        std::reverse(Test.begin() + a1, Test.begin() + a2);
        std::reverse(Test.begin() + b1, Test.begin() + b2);
        prnt(i, Test);
    }

    return 0;
}
*/