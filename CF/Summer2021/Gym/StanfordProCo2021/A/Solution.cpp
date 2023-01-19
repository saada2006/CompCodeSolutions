#include <iostream>
#include <algorithm>
#include <vector>

int main () {
    int HMax = -1, HMin = 2147483647;

    int n;
    std::cin >> n;

    std::vector<int> Survey(n);

    for(int& x : Survey) {
        std::cin >> x;
    }

    for(int i = 0; i < n; i++) {
        int H = 0;
        for(int j = i; j < n; j++) {
            H ^= Survey[j];

            HMax = std::max(HMax, H);
            HMin = std::min(HMin, H);
            std::cout << HMax << ' ' << HMin << '\n';
        }
    }

    std::cout << HMax - HMin;
}