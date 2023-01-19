#include <iostream>
#include <algorithm>
#include <cstdio>

struct Rect {
    int x[2];
    int y[2];

    int ComputeAreaOverlap(const Rect& Other) {
        int xo = ComputeBoundOverlap(x[0], x[1], Other.x[0], Other.x[1]);
        int yo = ComputeBoundOverlap(y[0], y[1], Other.y[0], Other.y[1]);
        return xo * yo;
    }

    int Area() {
        int dx = x[1] - x[0];
        int dy = y[1] - y[0];
        return dx * dy;
    }

private:
    static int ComputeBoundOverlap(int x00, int x01, int x10, int x11) {
        int compa = x01 - x00 + x11 - x10; 
        int upbnd = std::max(x01, x11) - std::min(x00, x10);
        if(compa > upbnd) {
            return upbnd - compa;
        } else {
            return 0;
        }
    }
};

Rect NextRect(void) {
    Rect Input;
    std::cin >> Input.x[0] >> Input.y[0] >> Input.x[1] >> Input.y[1];
    return Input;
}

int main() {
    freopen("square.in", "r", stdin);
    freopen("square.out", "w", stdout);

    Rect P0 = NextRect(), P1 = NextRect();
    int xmin = std::min(P0.x[0], P1.x[0]);
    int ymin = std::min(P0.y[0], P1.y[0]);
    int xmax = std::max(P0.x[1], P1.x[1]);
    int ymax = std::max(P0.y[1], P1.y[1]);  
    int xoff = xmax - xmin;
    int yoff = ymax - ymin;
    int side = std::max(xoff, yoff);
    int area = side * side;
    std::cout << area;  

    return 0;
}