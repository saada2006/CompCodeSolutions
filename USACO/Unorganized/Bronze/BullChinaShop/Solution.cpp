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

struct Piece {
    std::vector<std::string> Parts;
    int x[2], y[2];
    char& GetAtPosition(int x, int y) {
        return Parts.at(y).at(x);
    }
    char GetAtPosition(int x, int y) const {
        return Parts.at(y).at(x);
    }
};

void OffsetPiece(Piece& P, int x, int y) {
    std::rotate(P.Parts.begin(), P.Parts.begin() + y, P.Parts.end());
    for(auto& s : P.Parts) {
        std::rotate(s.begin(), s.begin() + x, s.end());
    }
}

Piece GetNextPiece(int n) {
    Piece Current;
    Current.Parts.resize(n);
    for(auto& s : Current.Parts) {
        std::cin >> s;
    }
    Current.x[0] = Current.y[0] = 9;
    Current.x[1] = Current.y[1] = -1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(Current.GetAtPosition(i, j) == '#') {
                Current.x[0] = std::min(Current.x[0], i);
                Current.y[0] = std::min(Current.y[0], j);
                Current.x[1] = std::max(Current.x[1], i);
                Current.y[1] = std::max(Current.y[1], j);
            }
        }
    }

    OffsetPiece(Current, Current.x[0], Current.y[0]);

    Current.x[1] -= Current.x[0];
    Current.x[0]  = 0;

    Current.y[1] -= Current.y[0];
    Current.y[0]  = 0;

    return Current;
}

/*
Plan to check for a piece: 

Compose different combinations of P0 and P1
Check each combo for a match to target

To compose all combinations of P0 and P1 we can offset each piece in such a way that:
All # are within the n*n board
When "fused" togheter no #s are taking up the same spot
*/

bool CheckPieces(const Piece& Target, const Piece& P0, const Piece P1, int n) {
    int RemainingSpace[2][2];

    RemainingSpace[0][0] = n - P0.x[1];
    RemainingSpace[0][1] = n - P0.y[1];
    RemainingSpace[1][0] = n - P1.x[1];
    RemainingSpace[1][1] = n - P1.y[1];

    for(int x0 = 0; x0 < RemainingSpace[0][0]; x0++) {
        for(int y0 = 0; y0 < RemainingSpace[0][1]; y0++) {
            Piece CurrentP0 = P0;
            OffsetPiece(CurrentP0, x0, y0);
            for(int x1 = 0; x1 < RemainingSpace[1][0]; x1++) {
                for(int y1 = 0; y1 < RemainingSpace[1][1]; y1++) {
                    Piece CurrentP1 = P1;
                    OffsetPiece(CurrentP1, x1, y1); 
                    // Fuse togheter
                    Piece Fused = Target;
                    bool ValidFuse = true;
                    for(int i = 0; ValidFuse && i < n; i++) {
                        for(int j = 0; ValidFuse && j < n; j++) {
                            bool Hash0 = (CurrentP0.GetAtPosition(i, j) == '#');
                            bool Hash1 = (CurrentP1.GetAtPosition(i, j) == '#');
                            if(Hash0 && Hash1) {
                                ValidFuse = false;
                            } else {
                                if(Hash0 || Hash1) {
                                    Fused.GetAtPosition(i, j) = '#';
                                } else {
                                    Fused.GetAtPosition(i, j) = '.';
                                }
                            }
                        }
                    }
                    if(!ValidFuse) {
                        continue;
                    } else {
                        bool ValidCompare = true;
                        for(int i = 0; ValidCompare && i < n; i++) {
                            for(int j = 0; ValidCompare && j < n; j++) {
                                if(Target.GetAtPosition(i, j) != Fused.GetAtPosition(i, j)) {
                                    ValidCompare = false;
                                }
                            }
                        }
                        if(ValidCompare) {
                            return true;
                        }
                    }
                }
            }
        }
    }

    return false;
}

int main() {
    InitIO("bcs");

    int n, k;
    std::cin >> n >> k;

    Piece Target = GetNextPiece(n);
    std::vector<Piece> Pieces(k);
    for(auto& p : Pieces) {
        p = GetNextPiece(n);
    }

    for(int i = 0; i < k; i++) {
        for(int j = i + 1; j < k; j++) {

            // Do these pieces work?
            if(CheckPieces(Target, Pieces[i], Pieces[j], n)) {
                std::cout << i + 1 << ' ' << j + 1 << '\n';
                return 0;
            }

        }
    }

    std::cout << "No solution found?\n";

    return 0;
}