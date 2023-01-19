#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

void solve() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::pair<int, int>> Joggers(m);
    int Idx = 0;
    for(auto& p : Joggers) {
        p.first = 1000000000;
        p.second = Idx++;
    }

    std::vector<int> PathsRun(m);
    std::vector<int> RunnablePaths(m);

    for(int i = 0; i < n; i++) {
        for(int& bij : RunnablePaths) {
            std::cin >> bij;
        }
        std::sort(RunnablePaths.begin(), RunnablePaths.end());
        std::sort(Joggers.rbegin(), Joggers.rend());

        for(int i = 0; i < m; i++) {
            PathsRun[Joggers[i].second] = RunnablePaths[i];
            Joggers[i].first = std::min(Joggers[i].first, RunnablePaths[i]);
        }

        for(const int x : PathsRun) {
            std::cout << x << ' ';
        }
        std::cout << '\n';
    }
}

int main() {
    int t;
    std::cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}