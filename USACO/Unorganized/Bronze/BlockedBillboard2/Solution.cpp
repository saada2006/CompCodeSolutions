#include <iostream>
#include <algorithm>
#include <cstdio>
#include <utility>

int ComputeBoundOverlap(int x00, int x01, int x10, int x11) {
        int compa = x01 - x00 + x11 - x10; 
        int upbnd = std::max(x01, x11) - std::min(x00, x10);
        if(compa > upbnd) {
            return compa - upbnd;
        } else {
            return 0;
        }
}

bool CheckRange(int x00, int x10, int x11) {
    bool ma = x00 <= x11;
    bool mi = x00 >= x10;
    return ma && mi;
}

bool CheckRange(int x00, int x01, int x10, int x11) {
    bool b0 = CheckRange(x00, x10, x11);
    bool b1 = CheckRange(x01, x10, x11);
    return b0 ^ b1;
}

bool CheckPoint(int x, int y, int x0, int y0, int x1, int y1) {
    bool yc = CheckRange(y, y0, y1);
    bool xc = CheckRange(x, x0, x1);
    return xc && yc;
}

int main() {
    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);

    int lx[2], ly[2];
    int fx[2], fy[2];

    std::cin >> lx[0] >> ly[0] >> lx[1] >> ly[1];
    std::cin >> fx[0] >> fy[0] >> fx[1] >> fy[1];

    int dx = lx[1] - lx[0];
    int dy = ly[1] - ly[0];

    int subtract = 0;

    bool B00 = CheckPoint(lx[0], ly[0], fx[0], fy[0], fx[1], fy[1]);
    bool B10 = CheckPoint(lx[1], ly[0], fx[0], fy[0], fx[1], fy[1]);
    bool B01 = CheckPoint(lx[0], ly[1], fx[0], fy[0], fx[1], fy[1]);
    bool B11 = CheckPoint(lx[1], ly[1], fx[0], fy[0], fx[1], fy[1]);

    bool C0 = B00 && B10 || B00 && B01;
    bool C1 = B11 && B10 || B11 && B01;
    bool I = C0 || C1;
    if(I) {
        int xov = ComputeBoundOverlap(fx[0], fx[1], lx[0], lx[1]);
        int yov = ComputeBoundOverlap(fy[0], fy[1], ly[0], ly[1]); 
        subtract = xov * yov;
    }

    int area = dx * dy - subtract;
    std::cout << area;

    return 0;
}

/*
    int xov = ComputeBoundOverlap(fx[0], fx[1], lx[0], lx[1]);
    int yov = ComputeBoundOverlap(fy[0], fy[1], ly[0], ly[1]);

    int dx = lx[1] - lx[0];
    int dy = ly[1] - ly[0];

    if(xov == dx && yov == dy) {
        std::cout << "0\n"; 
        return 0;
    } else if(xov == dx && CheckRange(fx[0], fx[1], lx[0], lx[1])) {
        dy -= yov;
    } else if(yov == dy && CheckRange(fy[0], fy[1], ly[0], ly[1])) {
        dx -= xov;
    }
*/