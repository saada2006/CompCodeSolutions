#include <iostream>

void solve() {
    int theta;
    std::cin >> theta;
    int div = theta - 180;
    if(-360 % div == 0) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
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