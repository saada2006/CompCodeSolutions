#include <iostream>

void solve() {
    int n, m, i, j;
    std::cin >> n >> m >> i >> j;
    std::cout << "1 1 " << n << ' ' << m << '\n';
}

int main() {
    int t;
    std::cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}