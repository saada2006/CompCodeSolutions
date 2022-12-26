#include <iostream>
#include <vector>
#include <algorithm>

void solve(void) {
    int m;
    std::cin >> m;

    std::vector<int> Matrix[2];

    Matrix[0].resize(m);
    Matrix[1].resize(m);

    int Coins[2]{0, 0};

    for(int& x : Matrix[0]) {
        std::cin >> x;
        Coins[0] += x;
    }
    Coins[0] -= Matrix[0].front();

    for(int& x : Matrix[1]) {
        std::cin >> x;
    }

    // Alice chooses optimal path by seeing whether going down and then going forward is a better idea than going down
    // Bob then sees checks if the coins under alice's path before she goes down is more than the ones on top

    // Brute force solution: check all drop points from 1...m, see which one lets Bob earn the least coins
    int MaxBobCoins = Coins[0];
    for(int i = 1; i < m; i++) {
        Coins[0] -= Matrix[0][i];
        Coins[1] += Matrix[1][i - 1];
        int CurrentCoins = std::max(Coins[0], Coins[1]);   // Bob's optimal choice
        MaxBobCoins = std::min(MaxBobCoins, CurrentCoins); // Alice's optimal choice
    }

    std::cout << MaxBobCoins << '\n';
}

int main() {
    int t;
    std::cin >> t;

    for(int i = 0; i < t; i++) {
        solve();
    }

    return 0;
}