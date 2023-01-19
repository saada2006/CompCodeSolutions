#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::string s[2];
    std::cin >> s[0] >> s[1];
    std::reverse(s[0].begin(), s[0].end());
    std::cout << (std::equal(s[0].begin(), s[0].end(), s[1].begin(), s[1].end()) ? "YES" : "NO") << '\n';
}