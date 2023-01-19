#include <iostream>
#include <algorithm>

void solve() {
    int s[3];
    std::cin >> s[0] >> s[1] >> s[2];
    std::sort(s, s + 3);
    std::cout << std::max(1, s[2] - s[1] - s[0] + 1) << '\n';
}

int main() {
    int t;
    std::cin >> t;

    for(int i = 0; i < t; i++) {
        solve();
    }

    return 0;
}