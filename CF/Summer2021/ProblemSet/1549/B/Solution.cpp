#include <iostream>
#include <string>

void solve() {
    int n;
    std::string g, e;
    std::cin >> n >> e >> g;

    int p = 0;
    for(int i = 0; i < n; i++) {
        if(g[i] == '1') {
            if(e[i] == '1') {
                int l = i - 1;
                int r = i + 1;
                if(l > -1 && e[l] == '1') {
                    e[l] = '0';
                } else if(r < n && e[r] == '1') {
                    e[r] = '0';
                } else {
                    continue;
                }
            }
            p++;
        }
    }

    std::cout << p << '\n';
}

int main() {
    int t;
    std::cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}