#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<std::pair<int, int>> Points(n);
    for(auto& xp : Points) {
        std::cin >> xp.first;
    }
    for(auto& yp : Points) {
        std::cin >> yp.second;
    }

    int MaxDist = 0;
    for(auto PointIter0 = Points.begin(); PointIter0 != Points.end(); PointIter0++) {
        for(auto PointIter1 = PointIter0 + 1; PointIter1 != Points.end(); PointIter1++) {
            int dx = PointIter0->first - PointIter1->first;
            int yx = PointIter0->second - PointIter1->second;
            int sq = dx * dx + yx * yx;
            MaxDist = std::max(MaxDist, sq);
        }
    }

    std::cout << MaxDist << '\n';
}