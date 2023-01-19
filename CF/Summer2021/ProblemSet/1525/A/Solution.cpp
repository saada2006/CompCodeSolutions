#include <iostream>
#include <numeric>

int gcd(int x, int y) {
    if(y == 0) {
        return x;
    } else {
        return gcd(y, x % y);
    }
}

int main() {
    int t;
    std::cin >> t;

    for(int i = 0; i < t; i++) {
        int k;
        std::cin >> k;

        int w = 100 - k;

        int div = gcd(k, w);
        k /= div;
        w /= div;

        std::cout << k + w << '\n';
    }
}