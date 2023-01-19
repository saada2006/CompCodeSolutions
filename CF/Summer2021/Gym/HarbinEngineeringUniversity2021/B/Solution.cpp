#include <iostream>
#include <string>

int main() {
    std::string S;
    std::getline(std::cin, S);

    if(S.length() > 1) {

        for(auto Iter = S.begin(); Iter != S.end() - 1; Iter++) {
            char Current = *Iter;
            char Next = *(Iter + 1); 

            if(Current != Next) {
                std::cout << 2;
                return 0;
            }
        }

    }

    std::cout << -1;

    return 0;
}