#include <iostream>
#include <algorithm>

void solve() {
    int n, a, b;
    std::string s;
    std::cin >> n >> a >> b >> s;
    int l = n * a;

    if(b >= 0) {
        l += n * b;
    } else {
        int Alterations = 0;
        char Previous = '\0';
        for(const char c : s) {
            if(c != Previous) {
                Alterations++;
                Previous = c;
            }
        }
        l += b * (1 + Alterations / 2);
    }

    std::cout << l << '\n';
}

int main() {
    int t;
    std::cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}