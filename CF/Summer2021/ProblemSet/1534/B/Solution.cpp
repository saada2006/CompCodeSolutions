#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdint>

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> Histogram(n);
    for(int& x : Histogram) {
        std::cin >> x;
    }

    std::int64_t Ugliness = 0;
    for(int i = 0; i < n; i++) {
        int Prev = (i == 0     ? 0 : Histogram[i - 1]);
        int Next = (i == n - 1 ? 0 : Histogram[i + 1]);
        int Curr = Histogram[i];

        Ugliness += std::max(Curr - Prev, 0) + std::max(Curr - Next, 0) - std::max(Curr - std::max(Prev, Next), 0);
    }

    std::cout << Ugliness << '\n';
}

int main() {
    int t;
    std::cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}