#include <iostream>

bool InRange(int a, int b, int x) {
    if(a > b) {
        std::swap(a, b);
    }
    return (a < x && x < b);
}

void solve() {
    int a[2], b[2], f[2];
    std::cin >> a[0] >> a[1]
             >> b[0] >> b[1]
             >> f[0] >> f[1];
    
    bool XColinear = (a[0] == b[0] && a[0] == f[0] && InRange(a[1], b[1], f[1]));
    bool YColinear = (a[1] == b[1] && a[1] == f[1] && InRange(a[0], b[0], f[0]));
    int Distance = 0;
    if(XColinear || YColinear) {
        Distance = 2;
    }
    Distance += std::abs(a[0] - b[0]) + std::abs(a[1] - b[1]);
    std::cout << Distance << '\n';
}

int main() {
    int t;
    std::cin >> t;
    for(int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}