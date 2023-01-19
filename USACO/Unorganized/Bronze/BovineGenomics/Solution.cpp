// Copy paste for fast USACO file I/O redirection
#include <iostream>
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

#include <vector>

char GetBaseBit(char c) {
    if(c == 'A') {
        return 1;
    } else if(c == 'T') {
        return 2;
    } else if(c == 'G') {
        return 4;
    } else {
        return 8;
    }
}

std::vector<char> GetOccuringBases(int n, int m) {
    std::vector<char> Sequence; 
    Sequence.resize(m);

    for(int i = 0; i < n; i++) {
        std::string CurrentCow;
        CurrentCow.reserve(m);
        std::cin >> CurrentCow;

        for(int j = 0; j < m; j++) {
            Sequence[j] |= GetBaseBit(CurrentCow[j]);
        }

    }

    return Sequence;
}

int main() {
    InitIO("cownomics");

    /*
    Strat:
    Assign bit to each letter:
    A - 1
    T - 2
    G - 3
    C - 4
    Use OR for each genome of every group to find which genomes occur
    For each gene position, if it fully made up for genes that occur only in it and not hte other gorup it works
    To find what genes are recurrent, we can use AND since any nucleotide base that occures in both immedialty invalide the gene
    Then we can check if the resulting value is nequal to 0
    */

   int n, m;
   std::cin >> n >> m;

   std::vector<char> OccuringBases[2] {GetOccuringBases(n, m), GetOccuringBases(n, m)};

    int Answer = 0;
   for(int i = 0; i < m; i++) {
       char RecurrentBases = (OccuringBases[0][i] & OccuringBases[1][i]);
       if(RecurrentBases == 0) {
           Answer++;
       }
   }

   std::cout << Answer;

    return 0;
}