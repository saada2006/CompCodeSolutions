#include <iostream>
#include <cstdint>

int main() {
    std::uint64_t x;
    std::cin >> x;

    while(true) {
        std::cout << x << ' ';
        if(x == 1) {
            break;
        }
        if(x % 2 == 0){
            x /=2;
        } else {
            x = 3 * x + 1;
        }
    }

    return 0;
}