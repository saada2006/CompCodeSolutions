#include <iostream>
#include <string>

int main() {
    int x = 0;

    int ic;
    std::cin >> ic;
    std::cin.ignore();

    for(int i = 0; i < ic; i++) {
        std::string Istruct;
        Istruct.reserve(3);

        std::getline(std::cin, Istruct);

        if(Istruct[1] == '+') {
            x++;
        } else {
            x--;
        }
    }

    std::cout << x;
}