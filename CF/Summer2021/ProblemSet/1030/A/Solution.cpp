#include <iostream>

int main() {
    int n;
    std::cin >> n;
    for(int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        if(x == 1) {
            std::cout << "HARD\n";
            return 0;
        }
    }
    std::cout << "EASY\n";
    return 0;
}