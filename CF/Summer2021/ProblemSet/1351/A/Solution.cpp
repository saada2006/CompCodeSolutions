#include <iostream>

void solve() {
    int a, b;
    std::cin >> a >> b;
    std::cout << a + b << '\n';
}

int main() {
    int t;
    std::cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}