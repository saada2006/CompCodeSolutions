#include <iostream>
#include <cstdint>
#include <algorithm>

void solve() {
    std::int64_t n, x, t;
    std::cin >> n >> x >> t;

    std::int64_t Dissatisfaction = 
}

int main() {
    int t;
    std::cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}

/*
int main() {
    int k;
    std::cin >> k;

    for(int i = 0; i < k; i++) {
        std::int64_t n, x, t;
        std::cin >> n >> x >> t;

        std::int64_t Dissatisfaction = 0;
        for(int c = 0; c < n; c++) {
            std::int64_t a = c * x + t;
            std::int64_t Start = 1 + a / x;
            std::int64_t End   = (a - t) / x;
            if(End < 0) {
                End = 0;
            }
            End++;
            Dissatisfaction += Start - End;
        }

        std::cout << Dissatisfaction << '\n';
    }

    return 0;
}
*/