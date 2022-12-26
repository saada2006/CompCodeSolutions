#include <iostream>
#include <cmath>
#include <cstdint>

void solve() {
    std::int64_t n;
    std::cin >> n;

    int Counter = -1;
    if(n % 2050 == 0) {
        std::int64_t Div = n / 2050;
        Counter = 0;
        while(Div != 0) {
            Counter += Div % 10;
            Div /= 10;
        }
    }

    std::cout << Counter << '\n';
}

int main() {
    int t;
    std::cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}