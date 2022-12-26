#include <iostream>

int main() {
    int n;
    std::cin >> n;
    int s = 0;
    for(int i = 0; i < n; i++) {
        int t, c;
        std::cin >> t >> c;
        if(c - t >= 2) {
            s++;
        }
    }
    std::cout << s << '\n';
    return 0;
}