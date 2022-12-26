#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <fstream>

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


char MapBits(char c) {
    char b;
    switch(c) {
        case 'A':
            b = 0;
            break;
        case 'T':
            b = 1;
            break;
        case 'G':
            b = 2;
            break;
        case 'C':
            b = 3;
            break;
    }
    return b;
}
 
char DNABitField(char a, char b, char c) {
    return a | (b << 2) | (c << 4);
}

int main() {
    InitIO("cownomics");

    int n, m;
    std::cin >> n >> m;
    std::cin.ignore();

    std::vector<char[50]> plain(n);
    std::vector<char[50]> spotty(n);
    for(auto& dna : plain) {
        std::string s;
        std::getline(std::cin, s);
        for(int i = 0; i < m; i++) {
            char c = s[i];
            dna[i] = MapBits(c);
        }
    }

    for(auto& dna : spotty) {
        std::string s;
        std::getline(std::cin, s);
        for(int i = 0; i < m; i++) {
            char c = s[i];
            dna[i] = MapBits(c);
        }
    }

    int combinations = 0;
    for(int i = 0; i < m; i++) {
        for(int j = i + 1; j < m; j++) {
            for(int k = j + 1; k < m; k++) {
                std::set<char> sequences;
                for(auto& dna : plain) {
                    sequences.insert(DNABitField(dna[i], dna[j], dna[k]));
                }

                bool noOverlap = true;
                for(auto& dna : spotty) {
                    if(sequences.count(DNABitField(dna[i], dna[j], dna[k])) != 0) {
                        noOverlap = false;
                        break;
                    }
                }

                if(noOverlap){
                    combinations++;
                }
            }
        }
    }

    std::cout << combinations << '\n';
}