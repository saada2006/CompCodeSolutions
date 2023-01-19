#include <iostream>
#include <string>

void solve() {
    std::string s;
    std::cin >> s;
    std::cout << s.size() << '\n';
}

int main() {
    int t;
    std::cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}