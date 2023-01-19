#include <iostream>
#include <algorithm>

// Removing any intersection point removes a stick from both red and green
// No move can be made once there are no red or green sticks (keyword here is or, not and)
// Each move removes a stick, so the number of moves till the end is min(r, g) (r = red, g = green)
// If the # of moves is divisible by 2, the player whose name is starting with m wins, otherwise a wins

int main() {
    int r, g;
    std::cin >> r >> g;
    int d = std::min(r, g);
    std::cout << (d % 2 == 0 ? "Malvika" : "Akshat");
    return 0;
}