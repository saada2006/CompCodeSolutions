#include <iostream>

int main() {
    int t;
    std::cin >> t;

    for(int i = 0; i < t; i++) {
        int a, b;
        std::cin >> a >> b;
        int NextFactor = b * ((a + b - 1) / b);
        std::cout << NextFactor - a << '\n';
    }

    return 0;
}