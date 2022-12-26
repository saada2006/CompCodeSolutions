#include <iostream>
#include <string>

void solve() {
    int n, a, b;
    std::cin >> n >> a >> b;
    std::string s;
    s.reserve(n);
    for(int i = 0; i < b; i++) {
        s.push_back('a' + i);
    }
    for(int i = b; i < a; i++) {
        s.push_back('a' + b - 1);
    }
    for(int i = a; i < n; i++) {
        s.push_back(s.at(i - a));
    }
    std::cout << s << '\n';
}

int main() {
    int t;
    std::cin >> t;
    for(int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}