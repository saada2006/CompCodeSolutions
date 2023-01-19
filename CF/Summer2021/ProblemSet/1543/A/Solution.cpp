#include <iostream>
#include <cstdint>
#include <algorithm>
#include <utility>

void solve() {
    std::int64_t a, b;
    std::cin >> a >> b;
    if(a > b) {
        std::swap(a, b);
    }

    std::int64_t m = b - a;
    if(m == 0) {
        std::cout << 0 << ' ' << 0 << '\n';
        return;
    }

    std::int64_t z = a;
    std::int64_t d = a - ((a / m) * m);
    std::int64_t u = (((a + m - 1) / m) * m) - a;

    std::cout << m << ' ' << std::min(z, std::min(d, u)) << '\n';
}

int main() {
    int t;
    std::cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}