#include <iostream>
#include <cstdint>

int main() {

    std::uint64_t n;
    std::cin >> n;

    std::uint64_t ExpectedSum = (n * (n+1)) / 2;
    std::uint64_t CountedSum = 0;
    // Ideally you would read everything into a std::istringstream first
    for(std::uint64_t i = 1; i < n; i++) {
        std::uint64_t Number;
        std::cin >> Number;
        CountedSum += Number;
    }

    std::cout << ExpectedSum - CountedSum << '\n';
}