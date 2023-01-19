#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>
#include <numeric>

int main() {
    int n;
    std::cin >> n;
    std::vector<std::int64_t> Weights(n);
    for(auto& W : Weights) {std::cin >> W;}

    int MaxBit = (1 << n) - 1;
    std::int64_t MinDiff = std::numeric_limits<std::int64_t>::max();
    for(int SubsetBin = 0; SubsetBin < MaxBit; SubsetBin++) {
        std::int64_t Counter[2] {0, 0}; 
        for(int Bit = 0; Bit < n; Bit++) {
            int BitBin = (1 << Bit);
            if(SubsetBin & BitBin) {
                Counter[0] += Weights[Bit];
            } else {
                Counter[1] += Weights[Bit];
            }
        }
        std::int64_t CurrentDifference = std::abs(Counter[0] - Counter[1]);
        MinDiff = std::min(MinDiff, CurrentDifference);
    }
    std::cout << MinDiff << '\n';
    return 0;
}


// RECURSIVE SOLUTION (VERY BAD, RECURSION IS FOR LOSERS)
/*
std::int64_t Search(std::int64_t Depth, std::int64_t Max, std::int64_t Subset0, std::int64_t Subset1, const std::vector<std::int64_t>& Set) {
    if(Depth == Max) {
        return std::abs(Subset0 - Subset1);
    } else {
        return std::min(Search(Depth + 1, Max, Subset0 + Set[Depth], Subset1, Set), Search(Depth + 1, Max, Subset0, Subset1 + Set[Depth], Set));
    }
}

int main() {
    int n;
    std::cin >> n;

    int Sum = 0;
    std::vector<std::int64_t> Weights(n);
    for(std::int64_t& W : Weights) {
        std::cin >> W;
        Sum += W;
    }
    
    std::int64_t Min = Search(0, n, 0, 0, Weights);
    std::cout << Min << '\n';

}
*/