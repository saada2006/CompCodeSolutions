#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

int clampusaco(int x, int x0, int x1) {
    return std::min(std::max(x, x0), x1);
}

bool isinrangeunidir(int x, int y0, int y1) {
    return (y1 > x && x > y0);
}

bool isinrange(int x, int y0, int y1) {
    return
        isinrangeunidir(x, y0, y1) ||
        isinrangeunidir(x, y1, y0);
}

int main() {
    freopen("buckets.in", "r", stdin);
    freopen("buckets.out", "w", stdout);    

    struct Coordinate {
        int x, y;
        Coordinate(void) : x(-1), y(-1) {} 
    };

    Coordinate Barn, Rock, Water; // Water is supposed to be lake but whatever

    for(int y = 0; y < 10; y++) {
        for(int x = 0; x < 10; x++) {
            char c;
            std::cin >> c;
            if(c == '\n') {
                std::cin >> c;
            }

            switch(c) {
                case 'B':
                    Barn.x = x;
                    Barn.y = y;
                    break;
                case 'R':
                    Rock.x = x;
                    Rock.y = y;
                    break;
                case 'L':
                    Water.x = x;
                    Water.y = y;
                    break;
            }
        }
    }

    bool ObstructX = (Rock.x == Barn.x && Rock.x == Water.x && isinrange(Rock.y, Water.y, Barn.y));
    bool ObstructY = (Rock.y == Barn.y && Rock.y == Water.y && isinrange(Rock.x, Water.x, Barn.x));
    bool Obstruction = ObstructX || ObstructY;
    
    int ManhattanDistance = std::abs(Barn.x - Water.x) + std::abs(Barn.y - Water.y) - 1;
    if(Obstruction) {
        ManhattanDistance += 2;
    }

    std::cout << ManhattanDistance;
    return 0;
}