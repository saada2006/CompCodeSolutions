#include <iostream>
#include <string>
#include <algorithm>

void solve() {
    int n;
    std::cin >> n;
    std::string Orig;
    Orig.reserve(n);
    std::cin >> Orig;

    std::string Copy = Orig;
    std::sort(Copy.begin(), Copy.end());

    int k = 0;
    for(int i = 0; i < n; i++) {
        if(Copy[i] != Orig[i]) {
            k++;
        }
    }

    std::cout << k << '\n';
}

int main() {
    int t;
    std::cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}