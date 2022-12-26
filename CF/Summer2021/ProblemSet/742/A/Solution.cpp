#include <iostream>

int main() {
    const int Solutions[] = {8, 4, 2, 6};
    int n;
    std::cin >> n;
    if(n == 0) {
        std::cout << '1';
    } else {
        n -= 1;
        std::cout << Solutions[n % 4]; 
    }
    return 0;
}