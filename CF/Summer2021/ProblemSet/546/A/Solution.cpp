#include <iostream>
#include <cstdint>

int main() {
    std::int64_t k, n, w;
    std::cin >> k >> n >> w;

    std::int64_t TotalPrice = k * (w * (w + 1)) / 2;
    std::int64_t FriendMoney = TotalPrice - n;
    if(FriendMoney < 0) {
        FriendMoney = 0;
    }

    std::cout << FriendMoney;
}