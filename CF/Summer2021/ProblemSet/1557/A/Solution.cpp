#include <iostream>
#include <cstdint>
#include <algorithm>
#include <iomanip>
#include <numeric>

void solve() {
    int n;
    std::cin >> n;

    std::int64_t Max = std::numeric_limits<std::int64_t>::min(), Sum = 0;
    for(int i = 0; i < n; i++) {
        std::int64_t a;
        std::cin >> a;

        Max = std::max(Max, a);
        Sum += a;
    }

    Sum -= Max;

    double SumAvg = Sum / (n - 1.0);
    std::cout << std::setprecision(1024) << SumAvg + (double)Max << '\n';
}

int main() {
    int t;
    std::cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}