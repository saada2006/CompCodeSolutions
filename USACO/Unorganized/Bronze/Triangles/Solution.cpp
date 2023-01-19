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
#include <utility>
#include <algorithm>

int main() {
    InitIO("triangles");

    int n;
    std::cin >> n;

    std::vector<std::pair<int, int>> Points(n);
    for(auto& P : Points) {
        std::cin >> P.first >> P.second;
    }

    int MaxArea2 = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            for(int k = j + 1; k < n; k++) {

                std::pair<int, int> Edge[3];
                Edge[0].first = std::abs(Points[i].first - Points[j].first);
                Edge[0].second = std::abs(Points[i].second - Points[j].second);

                Edge[1].first = std::abs(Points[i].first - Points[k].first);
                Edge[1].second = std::abs(Points[i].second - Points[k].second);

                Edge[2].first = std::abs(Points[j].first - Points[k].first);
                Edge[2].second = std::abs(Points[j].second - Points[k].second);

                bool AAX = false, AAY = false;
                int X, Y;
                for(int l = 0; l < 3; l++) {
                    if(Edge[l].first == 0) {
                        AAX = true;
                        Y = Edge[l].second;
                    } else if(Edge[l].second == 0) {
                        AAY = true;
                        X = Edge[l].first;
                    }
                }

                if(!(AAX && AAY)) {
                    continue;
                }

                int CurrentArea2 = X * Y;
                MaxArea2 = std::max(MaxArea2, CurrentArea2);
            }
        }
    }

    std::cout << MaxArea2 << '\n';

    return 0;
}