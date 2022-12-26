#include <iostream>

int d[30];

void solve() {
    int n;
    std::cin >> n;

    int c = -1;
    for(int i = 0; i < 30; i++) {
        if(n % d[i] == 0) {
            c = d[i];
            break;
        }
    }
    
    std::cout << n / c << std::endl;
}

int main() {
    int p2 = 2;
    for(int i = 0; i < 30; i++) {
        p2 *= 2;
        d[i] = p2 - 1;
    }
    int t;
    std::cin >> t;
    for(int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}