#include <iostream>

int main() {
    int n;
    std::cin >> n;

    int v[2] {100000, -100000}, i[2];
    for(int j = 0; j < n; j++) {
        int x;
        std::cin >> x;
        if(x > v[1]) {
            v[1] = x;
            i[1] = j;
        }
        if(x <= v[0]) {
            v[0] = x;
            i[0] = j;
        }
    }

    int d = n - 1 - i[0] + i[1];
    if(i[0] < i[1]) {
        d--;
    }
    std::cout << d << '\n';
    return 0;
}