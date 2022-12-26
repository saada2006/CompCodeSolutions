#include <iostream>
#include <vector>

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> Diff(n);
    for(int& x : Diff) {
        std::cin >> x;
    }
    int sum = 0;
    int asu = 0;
    for(int& x : Diff) {
        int y;
        std::cin >> y;
        int z = x - y;
        sum += z;
        asu += std::abs(z);
        x = z;
    }

    if(sum != 0) {
        std::cout << -1 << '\n';
        return;
    }

    std::vector<std::pair<int, int>> Operations;
    Operations.reserve(asu / 2);

    for(int i = 0; i < n; i++) {
        int i1 = i + 1;
        for(int j = i + 1; j < n; j++) {
            int j1 = j + 1;
            if(Diff[i] == 0) {
                break;
            }

            while(Diff[i] > 0 && Diff[j] < 0) {
                Diff[i]--;
                Diff[j]++;
                Operations.push_back(std::make_pair(i1, j1));
            }

            while(Diff[i] < 0 && Diff[j] > 0) {
                Diff[i]++;
                Diff[j]--;
                Operations.push_back(std::make_pair(j1, i1));
            }
        }
    }

    std::cout << Operations.size() << '\n';
    for(const auto& Op : Operations) {
        std::cout << Op.first << ' ' << Op.second << '\n';
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