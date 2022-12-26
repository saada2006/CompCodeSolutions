#include <iostream>

void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;
    int r = (n * m) / 2 - k;

    if(n % 2 == 1) {
        n--;
        k -= m / 2;
    }

    if(k >= 0 && k % 2 == 0) {
        int v = (m % 2) * n / 2;
        if(v + k <= (n * m) / 2) {
            std::cout << "YES\n";
            return;
        }
    }

    std::cout << "NO\n";
    
}

int main() {
    int t;
    std::cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}