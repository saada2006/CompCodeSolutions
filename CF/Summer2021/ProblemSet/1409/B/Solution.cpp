#include <iostream>
#include <cstdint>
#include <algorithm>
#include <numeric>

/*
Plan: 
Make a go down to b. If we encounter the barrier a - n in the process, we output b * (a - n)
If we encounter the barrier x, we output max(b - r, y) * x
Otherwise, subtract both by r / 2 and check against x and y bounds
*/

void solve() {
    std::int64_t a, b, x, y, n;

    std::cin >> a >> b >> x >> y >> n;
    std::int64_t MinAnswer = std::numeric_limits<std::int64_t>::max();

    std::int64_t MaxDistance[2];
    std::int64_t MinValue[2];

    MaxDistance[0] = std::min(n, a - x);
    MaxDistance[1] = std::min(n - MaxDistance[0], b - y);
    MinValue[0] = a - MaxDistance[0];
    MinValue[1] = b - MaxDistance[1];
    MinAnswer = MinValue[0] * MinValue[1];

    std::swap(a, b);
    std::swap(x, y);

    MaxDistance[0] = std::min(n, a - x);
    MaxDistance[1] = std::min(n - MaxDistance[0], b - y);
    MinValue[0] = a - MaxDistance[0];
    MinValue[1] = b - MaxDistance[1];
    MinAnswer = std::min(MinAnswer, MinValue[0] * MinValue[1]);

    std::cout << MinAnswer << '\n';
}

int main() {
    int t;
    std::cin >> t;
    for(int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}