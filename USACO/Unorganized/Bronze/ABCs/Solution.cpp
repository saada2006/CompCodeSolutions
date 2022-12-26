#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> Vec(7);
    for(int& x : Vec) {
        std::cin >> x;
    }

    std::sort(Vec.begin(), Vec.end());

    std::cout << Vec.front() << ' ';
    std::cout << Vec.at(1)   << ' ';
    std::cout << Vec.back() - Vec.at(1) - Vec.front()  << '\n';

    return 0;
}