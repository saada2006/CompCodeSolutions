#include <iostream>

int main() {
    int n;
    std::cin >> n;

    int p = 0;
    int s = 0;
    int a = 0;
    while (true) {
        int b = s + 1;
        int c = b * b;
        if(c > n) {
            break;
        }
        s = b;
        a = c;
    }

    
    p = 4 * s;
    int r = n - a;
    p += 2 * ((r + s - 1) / s);

    std::cout << p << '\n';
    return 0;
}