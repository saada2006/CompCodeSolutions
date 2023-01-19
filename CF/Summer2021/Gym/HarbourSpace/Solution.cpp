#include <iostream>
#include <vector>
#include <algorithm>

/*
Idea: find best pairing in the vector, remove it, and sum up their total instability
*/

int main() {    
    int n;
    std::cin >> n;
    if(n == 1) {
        std::cout << "0\n";
        return 0;
    }
    std::vector<int> Weights(n * 2);
    for(int& x : Weights) {
        std::cin >> x;
    }
    std::sort(Weights.begin(), Weights.end());

    std::vector<int>::iterator ErasePosition[2];
    int BestInstability;
    int InstabilitySum = 0;

    for(int i = 0; i < n - 1; i++) {
        BestInstability = 1000;

        for(auto Iter = Weights.begin(); Iter != Weights.end() - 1; Iter++) {
            auto NextIter = Iter + 1;
            int CurrentInstability = *NextIter - *Iter;
            if(CurrentInstability < BestInstability) {
                BestInstability = CurrentInstability;
                ErasePosition[0] = Iter;
                ErasePosition[1] = NextIter;
            }
        }

        InstabilitySum += BestInstability;
        Weights.erase(ErasePosition[0], ErasePosition[1] + 1);
    }

    std::cout << InstabilitySum << '\n';

    return 0;
}