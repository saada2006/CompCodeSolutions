#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>

int main() {
    freopen("teleport.in", "r", stdin);
    freopen("teleport.out", "w", stdout);

    int a, b, x, y;
    std::cin >> a >> b >> x >> y;

    int ab = std::abs(a - b);
    int axyb = std::abs(a - x) + std::abs(b - y);
    int ayxb = std::abs(a - y) + std::abs(b - x);
    int mindist = std::min(ab, std::min(axyb, ayxb));
    std::cout << mindist;
}