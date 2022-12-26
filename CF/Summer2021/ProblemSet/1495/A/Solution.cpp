#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

int main () {
    std::cout.precision(100);

    int t;
    std::cin >> t;

    for(int i = 0; i < t; i++) {
        int n;
        std::cin >> n;

        std::vector<int> Miners, Diamonds;
        Miners.reserve(n);
        Diamonds.reserve(n);

        for(int j = 0; j < 2 * n; j++) {
            int x, y;
            std::cin >> x >> y;
            
            if(x == 0) {
                Miners.push_back(std::abs(y));
            } else {
                Diamonds.push_back(std::abs(x));
            }
        }

        std::sort(Miners.begin(), Miners.end());
        std::sort(Diamonds.begin(), Diamonds.end());

        double Energy = 0.0;
        for(int k = 0; k < n; k++) {
            Energy += std::hypot((double)Miners[k], (double)Diamonds[k]);
        }

        std::cout << Energy << '\n';
    }
}