#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, m;
    std::cin >> m >> n;
    std::vector<int> f(n);
    for(int& x : f) {
        std::cin >> x;
    }
    std::sort(f.begin(), f.end());  
    int mindiff = 996;
    m--;
    for(int i = m; i < n; i++) {
        mindiff = std::min(mindiff, f[i] - f[i - m]);
    }
    std::cout << mindiff << '\n';
    return 0;
}