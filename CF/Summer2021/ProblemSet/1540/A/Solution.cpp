#include <iostream>
#include <algorithm>

void solve() {
    int n, m = 0;
    std::cin >> n;

    for(int i = 0; i < n; i++) {
        int j;
        std::cin >> j;
        m = std::max(m, j);
    }

    if(n == 1 || n == 2) {
        std::cout << 0 << '\n';
    } else {
        std::cout << -m << '\n';
    }
}

int main() {
    int t;
    std::cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}