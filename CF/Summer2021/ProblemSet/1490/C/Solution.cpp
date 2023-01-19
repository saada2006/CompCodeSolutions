#include <iostream>
#include <cmath>
#include <cstdint>

void solve() {
    std::int64_t x;
    std::cin >> x;

    std::int64_t CubeRootBound = std::lround(std::cbrt(x));
    if(CubeRootBound * CubeRootBound * CubeRootBound > x) {
        CubeRootBound--;
    }

    for(std::int64_t i = 1; i <= CubeRootBound; i++) {
        std::int64_t i3 = i * i * i;
        std::int64_t j3 = x - i3;

        std::int64_t j = std::lround(std::cbrt(j3));
        if(j >= 1 && j * j * j == j3) {
            std::cout << "YES\n";
            return;
        }
    }

    std::cout << "NO\n";
}

int main() {
    int t;
    std::cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}