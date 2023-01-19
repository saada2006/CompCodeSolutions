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

#include <string>
#include <vector>
#include <algorithm>
#include <array>

std::vector<std::vector<char>> GetDNA(int n, int m) {
    std::vector<std::vector<char>> DNASets(n);
    for(auto& DNA : DNASets) {
        std::string DNAString;
        std::cin >> DNAString;

        DNA.resize(m);
        std::copy(DNAString.begin(), DNAString.end(), DNA.begin());
        for(char& Base : DNA) {
            if(Base == 'A') {
                Base = 0;
            } else if(Base == 'T') {
                Base = 1;
            } else if(Base == 'G') {
                Base = 2;
            } else {
                Base = 3;
            }
        }
    }

    return DNASets;
}

void ComputeSequences(std::vector<std::vector<char>>& DNASet, int i, int j, int k, std::array<std::array<std::array<bool, 4>, 4>, 4>& Sequences) {
    for(const auto& DNA : DNASet) {
        int Idx[3];
        Idx[0] = DNA[i];
        Idx[1] = DNA[j];
        Idx[2] = DNA[k];

        Sequences[Idx[0]][Idx[1]][Idx[2]] = true;
    }
}

bool CheckSequences(std::array<std::array<std::array<bool, 4>, 4>, 4>* Sequences) {
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            for(int k = 0; k < 4; k++) {
                bool Seq0 = Sequences[0][i][j][k];
                bool Seq1 = Sequences[1][i][j][k];
                if(Seq0 && Seq1) {
                    return false;
                }
            }
        }
    }

    return true;
}

void InitArray(std::array<std::array<std::array<bool, 4>, 4>, 4>& Array) {
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            for(int k = 0; k < 4; k++) {
                Array[i][j][k] = false;
            }
        }
    }
}

int main() {
    InitIO("cownomics");

    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<char>> DNASets[2] {GetDNA(n, m), GetDNA(n, m)};

    int Answer = 0;
    for(int i = 0; i < m; i++) {

        for(int j = i + 1; j < m; j++) {

            for(int k = j + 1; k < m; k++) {

                std::array<std::array<std::array<bool, 4>, 4>, 4> Seq[2];
                InitArray(Seq[0]);
                InitArray(Seq[1]);

                ComputeSequences(DNASets[0], i, j, k, Seq[0]);
                ComputeSequences(DNASets[1], i, j, k, Seq[1]);

                if(CheckSequences(Seq)) {
                    Answer++;
                }
            }
        }
    }

    std::cout << Answer << '\n';

    return 0;
}