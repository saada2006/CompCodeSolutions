#include <iostream>

void solve() {
    int k;
    std::cin >> k;

    int Sum = 0;
    for(int i = 0; i < k; i++) {
        int b;
        std::cin >> b;
        Sum += b;
    }

    if(Sum < k) {
        std::cout << 1 << '\n';
    } else {
        std::cout << Sum - k << '\n';
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