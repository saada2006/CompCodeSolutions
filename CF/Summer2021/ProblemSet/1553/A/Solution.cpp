#include <iostream>

void solve() {
    int n;
    std::cin >> n;
    std::cout << (n + 1) / 10 << '\n';
}

int main() {
    int t;
    std::cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}