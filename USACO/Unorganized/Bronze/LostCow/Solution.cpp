#include <iostream>
#include <cstdio>
#include <algorithm>

int main() {
    freopen("lostcow.in", "r", stdin);
    freopen("lostcow.out", "w", stdout);

    int a, b;
    std::cin >> a >> b;

    int d = 0; // dist
    int p = a; // prev
    int o = 1; // offset
    int f = a; // farm
    while(!(std::min(f, p) <= b && b <= std::max(f, p))) {
        // b not in range
        // change offset

        p = f;
        f = a + o;
        o *= -2;
        d += std::abs(p - f);
    }

    // remove overtraveled dist
    d -= std::abs(f - p);
    d += std::abs(b - p); // travel to b from p

    std::cout << d;

    return 0;
}