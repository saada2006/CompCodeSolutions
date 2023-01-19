#include <iostream>
#include <cstdio>

int main() {
    freopen("promote.in", "r", stdin);
    freopen("promote.out", "w", stdout);

    int i[4], f[4];

    int ti = 0, tf = 0;

    for(int j = 0; j < 4; j++) {
        std::cin >> i[j] >> f[j];
        ti += i[j];
        tf += f[j];
    }

    int ne = tf - ti;
    int pb = i[0] + ne - f[0];
    int ps = i[1] + pb - f[1];
    int pg = i[2] + ps - f[2];
    
    std::cout << pb << '\n';
    std::cout << ps << '\n';
    std::cout << pg << '\n';

    return 0;
}