#include <iostream>

int main() {
    int n = 2021;
    for(int i = 1; i < n; i++) {
        if(n % i != 0) {
            std::cout << "No\n";
            return 0;
        }
    }
    std::cout << "Yes\n";
    return 0;
}