#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> Coins(n);
    int TotalMoney = 0;
    for(int& x : Coins) {
        std::cin >> x;
        TotalMoney += x;
    }
    std::sort(Coins.rbegin(), Coins.rend());
    int CurrentSum = 0;
    for(int i = 0; i < n; i++) {
        CurrentSum += Coins[i];
        if(CurrentSum * 2 > TotalMoney || i + 1 == n) {
            std::cout << i + 1 << '\n';
            return 0;
        }
    }
}