#include <iostream>
#include <vector>
#include <algorithm>

void solve() {
    int n, k;
    std::cin >> n >> k;

    std::vector<std::pair<int, int>> Arr(n);
    for(int i = 0; i < n; i++) {
        std::cin >> Arr[i].first;
        Arr[i].second = i;
    }
    std::sort(Arr.begin(), Arr.end());

    int NumGroups = 1;
    for(int i = 1; i < n; i++) {
        int j = i - 1;
        if(Arr[i].second != Arr[j].second + 1) {
            NumGroups++;
        }
    }

    std::cout << (NumGroups <= k ? "YES" : "NO") << '\n';
}

int main() {
    int t;
    std::cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}