#include <iostream>
#include <stdio.h>
#include <algorithm>

int ComputeMaxDominoes(int n, int m) {
    int Dominoes = m * (n / 2);    // dominoes in each strip mult num strips
    Dominoes += (n % 2) * m / 2; // remaining squares on the other side mult vertically stack dominoes
    return Dominoes;
};

int main () {
    #ifndef ONLINE_JUDGE
    freopen("Input.txt", "r", stdin);
    #endif

    int n, m;
    std::cin >> n >> m;

    std::cout << std::max(ComputeMaxDominoes(n, m), ComputeMaxDominoes(m, n)) << '\n';

    return 0;
}