#include <iostream>
#include <cstdint>
#include <numeric>
#include <algorithm>

void solve() {
    std::int64_t A, B;
    std::cin >> A >> B;

    if(B == 1) {
        std::cout << "NO\n";
        return;
    }

    std::int64_t AB = 3 * A * B;

    std::cout << "YES\n" << AB - A << ' ' << A << ' ' << AB << '\n';
}

int main() {
    int t;
    std::cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}