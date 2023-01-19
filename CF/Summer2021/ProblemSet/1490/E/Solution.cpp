#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

void solve() {
    int n;
    std::cin >> n;

    std::vector<std::pair<int, int>> Tokens(n);
    for(int i = 0; i < n; i++) {
        std::cin >> Tokens[i].first;
        Tokens[i].second = i + 1;
    }
    std::sort(Tokens.begin(), Tokens.end());

    std::vector<std::int64_t> AccumPoints;
    AccumPoints.reserve(n);
    std::int64_t Accum = 0;
    for(const auto& Player : Tokens) {
        Accum += Player.first;
        AccumPoints.push_back(Accum);
    }

    std::vector<int> Winners;
    Winners.reserve(n - 1);
    Winners.push_back(Tokens.back().second);
    for(int i = n - 1; i >= 1; i--) {
        if(AccumPoints[i - 1] >= Tokens[i].first) {
            Winners.push_back(Tokens[i - 1].second);
        } else {
            break;
        }
    }

    std::sort(Winners.begin(), Winners.end());
    std::cout << Winners.size() << '\n';
    for(const int x : Winners) {
        std::cout << x << ' ';
    }
    std::cout << '\n';
}

int main() {
    int t;
    std::cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}