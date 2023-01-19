#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

void solve() {
    int n, k;

    std::cin >> n >> k;
    std::vector<int> Temprature(n, 2000000000);
    std::vector<std::pair<int, int>> AirConditioners(k);

    for(auto& AC : AirConditioners) {
        std::cin >> AC.second;
        AC.second--;
    }
    for(auto& AC : AirConditioners) {
        std::cin >> AC.first;
        Temprature[AC.second] = AC.first;
    }

    std::sort(AirConditioners.begin(), AirConditioners.end());

    for(const auto& AC : AirConditioners) {
        std::pair<int, int> L, R;

        L.second = AC.second - 1;
        R.second = AC.second + 1;

        L.first = R.first = AC.first + 1;

        while(L.second >= 0) {
            if(L.first < Temprature[L.second]) {
                Temprature[L.second] = L.first;
            } else {
                break;
            }

            L.second--;
            L.first++;
        }

        while(R.second < n) {
            if(R.first < Temprature[R.second]) {
                Temprature[R.second] = R.first;
            } else {
                break;
            }

            R.second++;
            R.first++;
        }
    }

    for(const int Temp : Temprature) {
        std::cout << Temp << ' ';
    }
    std::cout << '\n';
}

int main() {
    int t;
    std::cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}