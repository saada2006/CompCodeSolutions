#include <iostream>

int main() {
    int n, k;
    std::cin >> n >> k;
    for(int i = 0; i < k; i++) {
        int div10 = n / 10;
        int div10mul10 = div10 * 10;
        if(div10mul10 == n) {
            n = div10;
        } else {
            n--;
        }
    }

    std::cout << n;

    return 0;
}