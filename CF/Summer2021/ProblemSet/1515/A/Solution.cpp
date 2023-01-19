#include <iostream>
#include <vector>

int main () {
    int t;
    std::cin >> t;

    for(int i = 0; i < t; i++) {
        int n, x;
        std::cin >> n >> x;

        std::vector<int> Gold(n);
        for(int& x : Gold) {
            std::cin >> x;
        }

        int GoldSum = 0;
        for(int j = 0; j < n; j++) {
            GoldSum += Gold[j];
            if(GoldSum == x) {
                // Switch with next array elem
                int NextJ = (j + 1) % n;
                std::swap(Gold[j], Gold[NextJ]);
                break;
            }
        }
        
        bool Valid = true;
        GoldSum = 0;
        for(int w : Gold) {
            GoldSum += w;
            if(GoldSum == x) {
                Valid = false;
                break;
            }
        }

        if(Valid) {
            std::cout << "YES\n";
            for(int w : Gold) {
                std::cout << w << ' ';
            }
            std::cout << '\n';
        } else {
            std::cout << "NO\n";
        }
    }

    return 0;
}