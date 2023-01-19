#include <iostream>
#include <cstdint>
#include <algorithm>

std::int64_t RoundUp(std::int64_t x, std::int64_t div) {
    x += div - 1;
    x -= x % div;
    return x;
}

void solve(void) {
    std::int64_t x;
    std::cin >> x;
    std::cout << std::max(6LL, x + 1) / 2 * 5 << '\n';
}

int main() {
    int t;
    std::cin >> t;

    for(int i = 0; i < t; i++) {
        solve();
    }

    return 0;
}