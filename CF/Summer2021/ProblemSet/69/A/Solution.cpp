#include <iostream>

int main() {
    int n;
    std::cin >> n;

    int netx = 0, nety = 0, netz = 0;

    for(int i = 0; i < n; i++) {
        int x, y, z;
        std::cin >> x >> y >> z;

        netx += x;
        nety += y;
        netz += z;
    }

    int len2 = netx * netx + nety * nety + netz * netz;
    std::cout << (len2 == 0 ? "YES" : "NO");
}