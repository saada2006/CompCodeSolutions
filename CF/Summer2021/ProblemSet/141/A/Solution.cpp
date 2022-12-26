#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::string s, n, j;
    std::cin >> s >> n >> j;
    s += n;
    std::sort(s.begin(), s.end());
    std::sort(j.begin(), j.end());
    std::cout << (std::equal(s.begin(), s.end(), j.begin(), j.end()) ? "YES\n" : "NO\n");
    return 0;
}