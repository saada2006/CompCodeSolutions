#include <iostream>
#include <cstdint>

int main() {
    std::int64_t x;
    std::cin >> x;

    if(x % 2 == 0) {
        std::cout << x / 2 << '\n';
    } else {
        std::cout << x / 2 - x << '\n';
    }

    return 0;
}