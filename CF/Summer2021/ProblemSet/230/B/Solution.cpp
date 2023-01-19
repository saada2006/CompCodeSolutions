#include <iostream>
#include <cmath>
#include <vector>
#include <utility>
#include <algorithm>

constexpr int MaxPrimes = 1000000;

int main() {
    std::vector<std::pair<int, bool>> PrimeCalculator(MaxPrimes);
    
    for(int i = 1; i < MaxPrimes; i++) {
        PrimeCalculator[i].first = i + 1;
        PrimeCalculator[i].second = PrimeCalculator[i].first % 2 == 1;
    }

    std::vector<std::int64_t> PrimeSquares;
    PrimeSquares.reserve(MaxPrimes);
    PrimeSquares.push_back(4);

    for(int i = 2; i < MaxPrimes; i += 2) {
        if(!PrimeCalculator[i].second) {
            continue;
        } else {
            std::int64_t x = PrimeCalculator[i].first;
            PrimeSquares.push_back(x * x); // Already sorted since we insert in increasing order
            for(int j = i + PrimeCalculator[i].first; j < MaxPrimes; j += PrimeCalculator[i].first) {
                PrimeCalculator[j].second = false;
            }
        }
    }

    int n;
    std::cin >> n;

    for(int i = 0; i < n; i++) {
        std::int64_t x;
        std::cin >> x;
        std::cout << (std::binary_search(PrimeSquares.begin(), PrimeSquares.end(), x) ? "YES\n" : "NO\n");
    }
}







// This solution was way too close, at 1996 MS (TLE = 2000 MS)

/* 
The only case in which a number can be a t-prime is if the 3rd divisior, let's say x, is x raised to the 2nd power, and x is prime
If it is the 3rd power or more power, it can be divided by any lower power
x^2 can be divided by x^2, x, or 1
*/

/*

bool prime(std::int64_t j) {
    if(j <= 1) {
        return false;
    }
    std::int64_t r = std::floor(std::sqrt(j)) + 1; // Add 1 in case
    for(int i = 2; i < r; i++) {
        if(j % i == 0) {
            return false;
        }
    }

    return true;
}

int main() {
    int n;
    std::cin >> n;
    for(int i = 0; i < n; i++) {
        std::int64_t x;
        std::cin >> x;
        std::int64_t r = std::lround(std::sqrt(x));
        std::cout << (r * r == x && prime(r) ? "YES\n" : "NO\n");
    }
    return 0;
}

*/