#include <iostream>
#include <algorithm>

// Start at max idx 
// Transfer numbers to next idx modulo 3 until max idx is n / 3
// Then transfer numbers to max idx - 1;

void solve() {
    int n;
    std::cin >> n;

    int c[3] {0, 0, 0};
    for(int i = 0; i < n; i++) {
        int a;
        std::cin >> a;
        c[a % 3]++;
    }


    int Curr = 0;
    for(int i = 1; i < 3; i++) {
        if(c[i] > c[Curr]) {
            Curr = i;
        }
    }

    int b = n / 3;
    int Prev = (Curr + 2) % 3;
    int Next = (Curr + 1) % 3;

    int Moves = 0;
    if(c[Prev] > b) {
        int Diff =  c[Prev] - b;
        Moves += Diff;
        c[Curr] += Diff;
    }

    int Diff = c[Curr] - b;
    Moves += Diff;
    c[Next] += Diff;
    Moves += c[Next] - b;

    std::cout << Moves << '\n';
}

int main() {
    int t;
    std::cin >> t;

    while(t--)
        solve();

    return 0;
}