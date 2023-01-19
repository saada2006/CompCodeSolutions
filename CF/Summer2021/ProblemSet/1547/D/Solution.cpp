#include <iostream>

void solve() {
    int n, Prev;
    std::cin >> n >> Prev;

    std::cout << 0 << ' ';
    for(int i = 1; i < n; i++) {
        int Curr;
        std::cin >> Curr;

        int Best = Prev | Curr;
        int YXor = Best ^ Curr;

        std::cout << YXor << ' ';

        Prev = Best;
    }

    std::cout << '\n';
}

int main() {
    int t;
    std::cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}