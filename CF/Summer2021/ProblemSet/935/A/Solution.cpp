#include <iostream>
#include <vector>
#include <cmath>

int main() {
    int n;
    std::cin >> n;

    int NumDiv = 0;
    for(int i = 2; i <= n; i++) {
        if(n % i == 0) {
            NumDiv++;
        }
    }

    std::cout << NumDiv << '\n';

    return 0;
}