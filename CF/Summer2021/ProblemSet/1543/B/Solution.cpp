#include <iostream>
#include <cstdint>

void solve() {
    int n;
    std::cin >> n;

    std::int64_t s = 0;
    for(int i = 0; i < n; i++) {
        std::int64_t x;
        std::cin >> x;
        s += x;
    }

    std::int64_t r = s % n;
    std::int64_t l = n - r;

    std::cout << r * l << '\n';
}

int main() {
    int t;
    std::cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}