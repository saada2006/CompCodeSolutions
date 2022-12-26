#include <iostream>

int main() {
    int t;
    std::cin >> t;

    for(int i = 0; i < t; i++) {
        int n;
        std::cin >> n;
        int r = n % 3;
        int c[2] {n / 3, n / 3};
        if(r != 0) {
            if(r == 1) {
                c[0]++;
            } else {
                c[1]++;
            }
        }
        std::cout << c[0] << ' ' << c[1] << '\n';
    }
    return 0;
}