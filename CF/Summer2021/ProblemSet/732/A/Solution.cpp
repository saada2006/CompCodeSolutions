#include <iostream>

int main() {
    int k, r;
    std::cin >> k >> r;

    int c[2] {-r, 0};
    int s = 0;

    while(true) {
        s++;
        c[0] += k;
        c[1] += k;
        if(c[0] % 10 == 0 || c[1] % 10 == 0) {
            std::cout << s << '\n';
            break;
        }
    }

    return 0;
}