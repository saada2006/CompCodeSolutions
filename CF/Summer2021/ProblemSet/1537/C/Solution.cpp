#include <iostream>
#include <algorithm>
#include <vector>

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> Mountains(n);
    for(int& x : Mountains) {
        std::cin >> x;
    }
    std::sort(Mountains.begin(), Mountains.end());

    int RightMountain = 0;
    int MinDiff = 1000000000;

    for(int i = 1; i < n; i++) {
        int CurDiff = Mountains[i] - Mountains[i - 1];
        if(CurDiff < MinDiff) {
            MinDiff = CurDiff;
            RightMountain = i;
        }
    }

    std::cout << Mountains[RightMountain - 1] << ' ';

    for(int i = RightMountain + 1; i < n; i++) {
        std::cout << Mountains[i] << ' ';
    }

    for(int i = 0; i < RightMountain - 1; i++) {
        std::cout << Mountains[i] << ' ';
    }

    std::cout << Mountains[RightMountain] << '\n';
}

int main() {
    int t;
    std::cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}

/*

 for(int i = 0; i < t; i++) {
        int n;
        std::cin >> n;

        std::vector<int> Mountains;
        Mountains.reserve(n);

        for(int j = 0; j < n; j++) {
            int Height;
            std::cin >> Height;
            Mountains.push_back(Height);
        }

        std::sort(Mountains.begin(), Mountains.end());

        int MinDiff = 2147483647;
        int H1Idx;
        int H1Value = 2147483647, H2Value;
        for(auto Iter = Mountains.begin(); Iter != Mountains.end() - 1; Iter++) {
            int CurrentDiff = *(Iter + 1) - *Iter;
            if(CurrentDiff < MinDiff && *Iter < H1Value) {
                H1Value = *Iter;
                H2Value = *(Iter + 1);

                H1Idx = std::distance(Mountains.begin(), Iter);

                MinDiff = CurrentDiff;
            }
        }

        std::vector<bool> UsedMountains(n);
        std::fill(UsedMountains.begin(), UsedMountains.end(), false);
        UsedMountains[H1Idx] = true;
        UsedMountains[H1Idx + 1] = true;

        std::vector<int> Obstacles; 
        Obstacles.reserve(n);
        Obstacles.push_back(H1Value);

        int PreviousNumber = H1Value;
        for(int NumUsedMountains = 2; NumUsedMountains < n; NumUsedMountains++) {
            
        }

    }

    */