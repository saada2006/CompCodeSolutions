#include <iostream>
#include <vector>
#include <algorithm>

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> b(n + 2);
    for(int& x : b) {
        std::cin >> x;
    }
    std::sort(b.begin(), b.end());

    std::int64_t sum = 0;
    for(int i = 0; i < n; i++) {
        sum += b[i];
    }

    if(b[n] == sum) {
        for(int i = 0; i < n; i++) {
            std::cout << b[i] << ' ';
        }
        std::cout << '\n';
        return;
    }

    sum += b[n];
    std::int64_t diff = sum - b[n + 1];

    if(std::binary_search(b.begin(), b.end() - 1, diff)) {
        for(int i = 0; i <= n; i++) {
            if(b[i] == diff) {
                diff = -1;
                continue;
            }
            std::cout << b[i] << ' ';
        }
        std::cout << '\n';
        return;
    }

    std::cout << -1 << '\n';
}

int main() {
    int t;
    std::cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}