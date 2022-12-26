#include <iostream>

void solve() {
    int n, Prev;
    std::cin >> n >> Prev;

    int Insertions = 0;
    for(int i = 1; i < n; i++) {
        int Curr;
        std::cin >> Curr;

        int a = Prev, b = Curr;
        if(a > b) {
            std::swap(a, b);
        }
        while(true) {
            int a2 = 2 * a;
            if(a2 < b) {
                Insertions++;
                a = a2;
            } else {
                break;
            }
        }

        Prev = Curr;
    }

    std::cout << Insertions << '\n';
}

int main() {
    int t;
    std::cin >> t;

    while(t--)
        solve();

    return 0;
}