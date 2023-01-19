#include <iostream>

int GetSteps(int& x, int move) {
    int orig = x;
    x %= move;
    return orig / move;
}

int main() {
    int x;
    std::cin >> x;

    int steps = GetSteps(x, 5);
    if(x != 0) {
        steps++;
    }

    std::cout << steps;
    return 0;
}