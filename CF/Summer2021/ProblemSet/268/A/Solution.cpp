#include <iostream>
#include <vector>
#include <utility>

int main() {
    int n;
    std::cin >> n;
    std::vector<std::pair<int, int>> Colors(n);
    for(auto& p : Colors) {
        std::cin >> p.first >> p.second;
    }
    
    int ChangingGames = 0;
    for(auto Home = Colors.begin(); Home != Colors.end(); Home++) { // Home is Host
        for(auto Iter = Colors.begin(); Iter != Colors.end(); Iter++) {
            if(Home == Iter) {
                continue;
            } else if(Home->first == Iter->second) {
                ChangingGames++;
            }
        }
    }
    std::cout << ChangingGames << '\n';
    return 0;
}