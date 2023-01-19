#include <iostream>
#include <cstdint>
#include <numeric>

int main() {
    std::uint32_t n;
    std::cin >> n;

    std::int64_t NumMovesRequired = 0;
    std::int64_t PreviousNumber = -99999999999;

    for(std::uint32_t i = 0; i < n; i++){
        std::int64_t CurrentNumber;
        std::cin >> CurrentNumber;

        if(CurrentNumber < PreviousNumber){
            NumMovesRequired += PreviousNumber - CurrentNumber;
        } else {
            PreviousNumber = CurrentNumber;
        }
    }

    std::cout << NumMovesRequired << '\n';

    return 0;
}