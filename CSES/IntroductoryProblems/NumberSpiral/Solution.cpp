#include <iostream>
#include <cstdint>
#include <ios>
#include <algorithm>
#include <cstdlib>

bool CheckEven(std::int64_t x) {
    return (x % 2 == 0); // Compile will optimize to last bit check
}

std::int64_t ComputeSolution(std::int64_t x, std::int64_t y) {
    std::int64_t PerfectSquareRoot = std::max(x, y);
    std::int64_t psx, psy;
    if(CheckEven(PerfectSquareRoot)) {
        psx = PerfectSquareRoot;
        psy = 1;
    } else {
        psx = 1;
        psy = PerfectSquareRoot;
    }

    std::int64_t ManhattanDistanceAbs = std::abs(psx - x) + std::abs(psy - y);
    std::int64_t Answer = (PerfectSquareRoot * PerfectSquareRoot) - ManhattanDistanceAbs;

    return Answer;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    for(int i = 0; i < n; i++){
        std::int64_t x, y;
        std::cin >> x >> y;
        std::cout << ComputeSolution(x, y) << '\n';
    }
}

/*
    // Find nearest perfect square
    // Horizontal perfect square if x is odd and x > y if y is even
    // Vertical perfect square if y is even and y > x if x is odd
    // Each square is part of one perfect square line so we only have to test for one of these
    // Compute manhattan distance between perfect square point (negate y for vertical)
    // Add manhattan if horizontal, subtract if vertical
    if(CheckEven())


*/