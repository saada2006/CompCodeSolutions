#include <iostream>

int main() {
    int n;
    std::cin >> n;

    int m = 1, s = 1, p = -1;
    for(int i = 0; i < n; i++) {
        if(p != -1) {
            int c;
            std::cin >> c;
            if(c >= p) {
                s++;
                p = c;
            }
            if(c < p || i + 1 == n) {
                m = (m > s ? m : s);
                s = 1;
                p = c;
            }
        } else {
            std::cin >> p;
        }
    }
    std::cout << m << '\n';

    return 0;
}