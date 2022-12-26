#include <iostream>
#include <algorithm>

int main() {
    int a, b;
    std::cin >> a >> b;
    int c = std::min(a, b);
    int d = std::max(a, b) - c;
    std::cout << c << ' ' << d / 2 << '\n';
    return 0;
}