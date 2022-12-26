#include <iostream>
#include <string>

// To determine if the fence is clockwise, pick a random point that is not a "corner" on the fence
// Then move perpendicular in the right direction until you hit the fence, which means it is cw, if it hits the 200x200 border then it is ccw

const size_t FieldDim = 101;

void solve() {
    std::string s;
    std::cin >> s;
    bool Field[FieldDim][FieldDim];

    for(int i = 0; i < FieldDim; i++) {
        std::fill_n(Field[i], FieldDim, false);
    }

    int x = FieldDim / 2, y = FieldDim / 2;
    for(const char c : s) {
        Field[y][x] = true;
        switch (c)
        {
        case 'N':
            y++;
            break;
        case 'S':
            y--;
            break;
        case 'E':
            x++;
            break;
        case 'W':
            x--;
            break;
        }
    }

    bool ccw = true;

    for(const char c : s) {
        int dx, dy;
        switch (c)
            {
            case 'N':
                y++;
                dx = 1;
                dy = 0;
                break;
            case 'S':
                y--;
                dx = -1;
                dy = 0;
                break;
            case 'E':
                x++;
                dx = 0;
                dy = -1;
                break;
            case 'W':
                x--;
                dx = 0;
                dy = 1;
                break;
        }
        int xp = x, yp = y;
        int xp2 = xp + dx;
        int yp2 = yp + dy;
        bool f[2] {true, true};
        while(xp2 < FieldDim && xp2 >= 0 && yp2 < FieldDim && yp2 >= 0) {
            if(Field[yp2][xp2]) {
                f[0] = false;
                break;
            }
            xp2 += dx;
            yp2 += dy;
        }
        xp2 = xp - dx;
        yp2 = yp - dy;
        while(xp2 < FieldDim && xp2 >= 0 && yp2 < FieldDim && yp2 >= 0) {
            if(Field[yp2][xp2]) {
                f[1] = false;
                break;
            }
            xp2 -= dx;
            yp2 -= dy;
        }
        if(f[0] ^ f[1]) {
            ccw = false;
            break;
        }
    }

    std::cout << (ccw ? "CCW" : "CW") << '\n';
}

int main() {
    int t;
    std::cin >> t;

    for(int i = 0; i < t; i++) {
        solve();
    }

    return 0;
}