#include <iostream>
#include <string>

void solve() {
    std::string s;
    std::cin >> s;

    size_t P = s.find('a');
    if(P == std::string::npos) {
        std::cout << "NO\n";
        return;
    }
    int L = P - 1, R = P + 1;

    char Search = 'b';
    for(int i = 1; i < s.size(); i++, Search++) {
        if(L >= 0 && s[L] == Search) {
            L--;
        } else if(R < s.size() && s[R] == Search) {
            R++;
        } else {
            std::cout << "NO\n";
            return;
        }
    }

    std::cout << "YES\n";
}

int main() {
    int t;
    std::cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}