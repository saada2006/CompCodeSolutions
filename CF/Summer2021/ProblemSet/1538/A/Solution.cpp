#include <iostream>
#include <algorithm>

void solve() {
    int n;
    std::cin >> n;

    int m[2] {n, 0}; // min, max
    int v[2] {0, 0}; // min, max

    for(int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        if(x < m[0]) {
            m[0] = x;
            v[0] = i;
        }
        if(x > m[1]) {
            m[1] = x;
            v[1] = i;
        }
    }

    // Destroy the stone closest to the the end, then choose the end to destroy the second stone from
    if(v[0] > v[1]) {
        // Ensure sorted
        std::swap(v[0], v[1]);
        //std::swap(m[0], m[1]); // lol nobody cares about you anymore
    }

    int Moves[3];

    Moves[0] = n - v[0];
    Moves[1] = v[1] + 1;
    Moves[2] = v[0] + 1 + n - v[1];

    std::cout << std::min(std::min(Moves[0], Moves[1]), Moves[2]) << '\n';
}

int main() {
    int t;
    std::cin >> t;

    for(int i = 0; i < t; i++) {
        solve();
    }

    return 0;
}