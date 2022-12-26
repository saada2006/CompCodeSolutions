#include <iostream>

int NumDigits(int v) {
    int Digits = 0;
    while(v != 0) {
        v /= 10;
        Digits++;
    }
    return Digits;
}

void solve() {
    int a, b, c;
    std::cin >> a >> b >> c;

    int gcd = 1;
    for(int i = 1; i < c; i++) {
        gcd *= 10;
    }

    int x = gcd, y = gcd;
    while(NumDigits(x) != a) {
        x *= 2;
    }

    while(NumDigits(y) != b) {
        y *= 3;
    }

    std::cout << x << ' ' << y << '\n';
}

int main() {
    int t;
    std::cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}