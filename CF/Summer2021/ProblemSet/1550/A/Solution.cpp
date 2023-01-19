#include <iostream>

void solve() {
    int n;
    std::cin >> n;

    int a = -1;
    int m = 0;
    while(true) {
        a += 2;
        n -= a;
        m++;
        if(n <= 0) {
            break;
        }
    }

    std::cout << m << '\n';
}

int main() {
    int t;
    std::cin >> t;

    while(t--)
        solve();

    return 0;
}