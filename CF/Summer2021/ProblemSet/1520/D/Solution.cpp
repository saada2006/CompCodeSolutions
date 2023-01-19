#include <iostream>
#include <map>

void solve() {
    int n;
    std::cin >> n;

    std::map<int, std::int64_t> Freq;
    for(int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        Freq[x - i]++;
    }

    std::int64_t NumPairs = 0;
    for(const auto& Line : Freq) {
        NumPairs += (Line.second * (Line.second - 1)) / 2;
    }
    std::cout << NumPairs << '\n';
}

int main() {
    int t;
    std::cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}