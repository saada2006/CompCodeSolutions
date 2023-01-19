#include <iostream>
#include <cstdint>

void solve() {
    std::int64_t n, m, i;
    std::cin >> n >> m >> i;
    i--;
    std::int64_t x = i / n;
    std::int64_t y = i % n;
    std::cout << y * m + x + 1 << '\n';
}

int main() {
    int t;
    std::cin >> t;

    while(t--)
        solve();

    return 0;
}