#include <iostream>
#include <cstdio>
#include <algorithm>

int main() {
    freopen("paint.in", "r", stdin);
    freopen("paint.out", "w", stdout);

    int a, b, c, d;
    std::cin >> a >> b >> c >> d;

    int paint = b - a + d - c;
    int overlap = 0;
    int end2end = std::max(b, d) - std::min(a, c);
    if(end2end < paint) {
        overlap = paint - end2end;
    }

    std::cout << paint - overlap;
}