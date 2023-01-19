#include <iostream>
#include <string>

int main() {
    std::string alphabet, herd;
    std::cin >> alphabet >> herd;

    size_t Position = alphabet.size();
    int NumMinTimesSaid = 0;
    for(const char c : herd) {
        size_t Current = alphabet.find(c);
        if(Current <= Position) {
            NumMinTimesSaid++;
        }
        Position = Current;
    }

    std::cout << NumMinTimesSaid << '\n';
    return 0;
}