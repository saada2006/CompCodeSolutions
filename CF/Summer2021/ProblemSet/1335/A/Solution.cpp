#include <iostream>

// At most alice gets n - 1 candies
// At least she gets n / 2 + 1
// Do most - least

int main() {
    int t;
    std::cin >> t;
    
    for(int i = 0; i < t; i++) {
        int n;
        std::cin >> n;
        int m = n / 2 + 1;
        std::cout << n - m << '\n';
    }

    return 0;
}