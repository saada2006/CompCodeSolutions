#include <iostream>
#include <string>

void ConvertLowerCase(std::string& s) {
    for(char& c : s) {
        c |= 32;
    }
}

int main() {
    std::string s0, s1;

    std::getline(std::cin, s0);
    std::getline(std::cin, s1);

    ConvertLowerCase(s0);
    ConvertLowerCase(s1);

    for(int i = 0; i < s0.length(); i++) {
        char c0 = s0[i], c1 = s1[i];
        if(c0 > c1) {
            std::cout << '1';
            return 0;
        } else if (c0 < c1) {
            std::cout << "-1";
            return 0;
        }
    }

    std::cout << '0';
    return 0;
}