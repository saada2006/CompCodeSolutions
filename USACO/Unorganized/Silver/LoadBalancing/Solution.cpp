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

Plan: We can "transfer" points from one part of the partition to the other each time we update the fence
Basically, we first create an array of coordinates sorted by x
Then we start with an initial y-value and keep increasing it until the next y-value is larger
We count these y-values to initalize the lower array to it and the top one to n - lower
We can then iterate through x like we did with y to find the arrangments
*/

struct Coordinate {
    int x, y;
};

int main() {
    InitIO("balancing");

    int n;
    std::cin >> n;
    if(n == 1) {
        std::cout << "1\n";
        return 0;
    }

    std::vector<Coordinate> Positions[2];
    Positions[0].resize(n);
    Positions[1].resize(n);

    for(auto& P : Positions[0]) {
        std::cin >> P.x >> P.y;
    }

    std::copy(Positions[0].begin(), Positions[0].end(), Positions[1].begin());
    std::sort(Positions[0].begin(), Positions[0].end(), [](const Coordinate& C0, const Coordinate& C1) {return C0.x < C1.x;});
    std::sort(Positions[1].begin(), Positions[1].end(), [](const Coordinate& C0, const Coordinate& C1) {return C0.y < C1.y;});

    int InitCounter[2][2] {{0, 0,}, {0, n,}}; // [x g] [y g]
    int YLevel = Positions[1].front().y;
    int MinAnswer = 99999;
    for(int i = 0; i < n; i++) {
        if(Positions[1][i].y == YLevel) {
            InitCounter[1][1]--;
            InitCounter[1][0]++;
            continue;
        }
        YLevel = Positions[1][i].y;
        i--;

        int CurrentCounter[2][2];
        std::copy_n(InitCounter[0], 2, CurrentCounter[0]);
        std::copy_n(InitCounter[1], 2, CurrentCounter[1]);

        int XLevel = Positions[0].front().x;
        for(int j = 0; j < n; j++) {
            if(Positions[0][j].x == XLevel) {
                if(Positions[0][j].y > YLevel - 1) {
                    CurrentCounter[0][1]++;
                    CurrentCounter[1][1]--;
                } else {
                    CurrentCounter[0][0]++;
                    CurrentCounter[1][0]--;
                }
            } else {
                XLevel = Positions[0][j].x;
                int TotalMax = std::max(std::max(CurrentCounter[0][0], CurrentCounter[1][0]), std::max(CurrentCounter[0][1], CurrentCounter[1][1]));
                MinAnswer = std::min(MinAnswer, TotalMax);
                j--;
            }
        }
    }
    
    std::cout << MinAnswer << '\n';

    return 0;
}