#include <iostream>

int absi32(int x) {
    return x < 0 ? -x : x;
}

int main() {

    for(int y = 1; y <= 5; y++) {
        for(int x = 1; x <= 5; x++) {
            int v;
            std::cin >> v;
            if(v == 1) {
                std::cout << absi32(3 - y) + absi32(3 - x);
                return 0;
            }
        }
    }

    std::cout << "Error\n";
    return 0;
}