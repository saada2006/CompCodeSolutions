#include <iostream>
#include <cmath>

bool IsPerfectSquare(int x) {
    int b = 0;
    int sq = 0;
    while(sq < x) {
        b++;
        sq = b * b;
    }

    return (sq == x);
}

bool CanMakeSquare(int x) {
    if(x % 2 == 0) {
        if(IsPerfectSquare(x / 2)) {
            return true;
        } else if (x % 4 == 0 && IsPerfectSquare(x / 4)) {
            return true;
        }
    }

    return false;
}

int main() {
    int t;
    std::cin >> t;

    for(int i = 0; i < t; i++) {
        int NumTriangles;
        std::cin >> NumTriangles;
        std::cout << (CanMakeSquare(NumTriangles) ? "YES\n" : "NO\n");
    }

    return 0;
}