#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

int main() {
    int n, l;
    std::cin >> n >> l;
    std::vector<int> Lights(n);
    for(int& x : Lights) {
        std::cin >> x;
    }
    std::sort(Lights.begin(), Lights.end());
    double MinRadius = std::max(Lights.front(), l - Lights.back());
    for(int i = 0; i < n - 1; i++) {
        int Next = Lights[i + 1];
        int Curr = Lights[i    ];
        double MidPoint = (Next + Curr) / 2.0;
        MinRadius = std::max(MinRadius, MidPoint - Curr);
    }
    std::cout << std::setprecision(128) << MinRadius << '\n';

    return 0;
}