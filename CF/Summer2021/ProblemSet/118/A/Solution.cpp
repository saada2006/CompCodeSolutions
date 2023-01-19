#include <iostream>
#include <string>

int main() {
    std::string s;
    std::getline(std::cin, s);

    for(char c : s) {
        constexpr char BitConvertLowercse = ~32;
        c &= BitConvertLowercse;
        c += 32;

        if(c != 'a' && c != 'o' && c != 'y' && c != 'e' && c != 'u' && c != 'i') {
            std::cout << '.' << c;
        }
    }
}