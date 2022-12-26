#include <iostream>
#include <algorithm>
#include <cstdint>

std::uint64_t CountFactor(std::uint64_t i, std::uint64_t d, std::uint64_t& x) {
    int factor = 0;
    while (i % d == 0) {
        factor++;
        i /= d;
    }
    x = i;
    return factor;
}

std::uint64_t CountFactor(std::uint64_t i, std::uint64_t d) {
    int factor = 0;
    while (i % d == 0) {
        factor++;
        i /= d;
    }
    return factor;
}

std::uint64_t RoundNearest(std::uint64_t x, std::uint64_t n) {
    x += (n - 1);
    x /= n;
    x *= n;
    return x;
}

int main() {
    std::uint64_t a, b;
    std::cin >> a >> b;

    std::uint64_t a2 = RoundNearest(a, 2), a5 = RoundNearest(a, 5); // a rounded to nearest n
    std::uint64_t x2, x5; // "remainder" of factorization
    std::uint64_t f2 =  CountFactor(a2, 2, x2), f5 =  CountFactor(a5, 5, x5); // power of the factors of a
    std::uint64_t d2 = a2 / x2, d5 = a5 / x5;  // factors of a 
    std::uint64_t e2 = b / d2, e5 = b / d5; // ending point of loop

    std::uint64_t s2 = 0, s5 = 0; // Solution

    for(uint64_t i = x2; i <= e2; i++) {
        std::uint64_t xl;
        std::uint64_t cf = CountFactor(i, 2, xl);
        if(cf != 0) {
            s2 = std::max(s2, f2 + cf); // f2 + cf
            
        }
    }

    for(uint64_t i = x5; i <= e5; i++) {
        s5 = std::max(s5, f5 + CountFactor(i, 5));
    }

    std::cout << std::min(s2, s5);
}