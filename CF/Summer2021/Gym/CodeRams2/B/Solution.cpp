#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>

int main () {
    int n, m, k;
    std::cin >> n >> m >> k;

    std::vector<std::uint64_t> Data(n);
    for(auto& x : Data) {
        std::cin >> x;
    }

    std::sort(Data.rbegin(), Data.rend());

    std::uint64_t sum = 0;
    for(int i = 0; i < m + (m - 1) * (k - 1); i++) {
        sum += Data[i];
    }

    std::cout << sum;
}