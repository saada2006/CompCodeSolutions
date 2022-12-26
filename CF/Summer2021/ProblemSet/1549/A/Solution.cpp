#include <iostream>

void solve() {
    int x;
    std::cin >> x;

    for(int i = 2; i < x; i++) {
        int RoundDown = x - x % i;
        if(RoundDown > 2) {
            std::cout << i << ' ' << RoundDown << '\n';
            break;
        }
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