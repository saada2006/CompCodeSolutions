#include <iostream>

int main() {
    int t;
    std::cin >> t;

    for(int i = 0; i < t; i++) {
        int n;
        std::cin >> n;

        int n2 = 2 * (n / 2);
        for(int j = 1; j <= n2; j++) {
            if(j == n2) {
                if(n != n2) {
                    std::cout << n << ' ' << j - 1 << '\n';
                } else {
                    std::cout << j - 1 << '\n';
                }
            } else if (j % 2 == 1) {
                std::cout << j + 1 << ' ';
            } else {
                std::cout << j - 1 << ' ';
            }
        }
        
    }

    return 0;
}