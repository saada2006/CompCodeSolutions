#include <iostream>

void solve(void) {
    int n;
    std::cin >> n;
    for(int z = 0; z <= n; z += 2020) {
        int o = n - z;
        if(o % 2021 == 0) {
            std::cout << "YES\n";
            return;
        }
    }
    std::cout << "NO\n";
}

int main() {
    int t;
    std::cin >> t;
    for(int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}