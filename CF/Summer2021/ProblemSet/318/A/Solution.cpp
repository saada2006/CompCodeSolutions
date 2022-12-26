#include <iostream>
#include <cstdint>

int main() {
    std::int64_t n, k;
    std::cin >> n >> k;
    std::int64_t num[2] {(n + 1) / 2, n / 2};
    num[1] += num[0];
    if(k <= num[0]) {
        std::cout << k * 2 - 1;
    } else {
        k -= num[0];
        std::cout << k * 2;
    }
    std::cout << '\n';
    return 0;
}