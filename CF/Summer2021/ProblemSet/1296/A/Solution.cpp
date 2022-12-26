#include <iostream>

int main() {
    int t;
    std::cin >> t;

    for(int it  = 0; it < t; it++) {
        int n;
        std::cin >> n;

        int numodd = 0;
        for(int i = 0; i < 2 * n; i++) {
            int j;
            std::cin >> j;

            if(j % 2 == 1) {
                numodd++;
            }
        }

        std::cout << (numodd == n) ? "Yes\n" : "No\n";
    }

    return 0;
}