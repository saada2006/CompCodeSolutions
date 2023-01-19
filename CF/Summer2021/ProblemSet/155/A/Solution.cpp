#include <iostream>

int main() {
    int n;
    std::cin >> n;

    int min, max;
    std::cin >> min; max = min;
    int nazming = 0;
    for(int i = 1; i < n; i++) {
        int curr;
        std::cin >> curr;
        if(curr < min) {
            min = curr;
            nazming++;
        } else if(curr > max) {
            max = curr;
            nazming++;
        }
    }
    std::cout << nazming;
    return 0;
}