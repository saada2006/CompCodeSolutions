#include <iostream>

int main() {
    int n, h;
    std::cin  >> n >> h;
    int r = 0;
    for(int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        if(x > h) {
            r += 2;
        } else {
            r++;
        }
    }
    std::cout << r << '\n';
    return 0;
}