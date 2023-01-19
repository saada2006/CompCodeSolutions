#include <iostream>
#include <algorithm>

int main() {
    int t;
    std::cin >> t;

    for(int i = 0; i < t; i++) {
        int n;
        std::cin >> n;
        int c = 0;
        int d = 1;
        for(int i = 0; i < 9; i++) {
            c += std::min(n, d * 9) / d;
            d = d * 10 + 1;
        }
        std::cout << c << '\n';
    }

    return 0;
}