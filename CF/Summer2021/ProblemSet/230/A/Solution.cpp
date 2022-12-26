#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

int main() {
    int s, n;
    std::cin >> s >> n;
    std::vector<std::pair<int, int>> Dragons(n);
    for(auto& Pair : Dragons) {
        std::cin >> Pair.first >> Pair.second;
    }
    std::sort(Dragons.begin(), Dragons.end());
    for(const auto& Difficulty : Dragons) {
        if(s > Difficulty.first) {
            s += Difficulty.second;
        } else {
            std::cout << "NO\n";
            return 0;
        }
    }

    std::cout << "YES\n";
    return 0;
}