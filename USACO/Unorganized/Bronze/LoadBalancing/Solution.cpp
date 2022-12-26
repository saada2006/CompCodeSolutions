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
Noob solution:
For each possible split between first and next cow on x (for each on y in nested loop):
    Filter each cow into group counters
    Find max in all groups
    Update max counter
*/

bool CompareAxis = false;

struct Coordinate {
    int x, y;

    bool operator<(const Coordinate& Comp) {
        if(CompareAxis) {
            return this->y < Comp.y;
        } else {
            return this->x < Comp.x;
        }
    }
};

int main() {
    InitIO("balancing");

    int n, b;
    std::cin >> n >> b;

    if(n == 1) {
        std::cout << "1\n";
        return 0;
    }

    std::vector<Coordinate> CowPositions[2];
    CowPositions[0].resize(n);
    CowPositions[1].resize(n);
    for(auto& Coord : CowPositions[0]) {
        std::cin >> Coord.x >> Coord.y;
    }

    std::sort(CowPositions[0].begin(), CowPositions[0].end());
    std::copy(CowPositions[0].begin(), CowPositions[0].end(), CowPositions[1].begin());
    CompareAxis = true;
    std::sort(CowPositions[1].begin(), CowPositions[1].end());

    Coordinate Compare;
    int CowMin = 1000;
    for(int i = 1; i < n; i++) {
        Compare.x = (CowPositions[0][i - 1].x + CowPositions[0][i].x) / 2;
        for(int j = 1; j < n; j++) {
            Compare.y = (CowPositions[1][j - 1].y + CowPositions[1][j].y) / 2;
            int Counter[2][2] {{0, 0}, {0, 0}};
            for(auto& Coord : CowPositions[0]) {
                if(Coord.x > Compare.x) {
                    if(Coord.y > Compare.y) {
                        Counter[1][1]++;
                    } else {
                        Counter[1][0]++;
                    }
                } else {
                    if(Coord.y > Compare.y) {
                        Counter[0][1]++;
                    } else {
                        Counter[0][0]++;
                    }                    
                }
            }

            int Max[3];
            Max[0] = std::max(Counter[0][0], Counter[0][1]);
            Max[1] = std::max(Counter[1][0], Counter[1][1]);
            Max[2] = std::max(Max[0], Max[1]);
            CowMin = std::min(CowMin, Max[2]);
        }
    } 

    std::cout << CowMin << '\n';

    return 0;
}