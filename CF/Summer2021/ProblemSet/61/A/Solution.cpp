#include <iostream>

int main() {
    std::string s[2];
    std::cin >> s[0] >> s[1];

    for(int i = 0; i < s[0].size(); i++) {
        if(s[0][i] == s[1][i]) {
            std::cout << '0';
        } else {
            std::cout << '1';
        }
    }

    return 0;
}