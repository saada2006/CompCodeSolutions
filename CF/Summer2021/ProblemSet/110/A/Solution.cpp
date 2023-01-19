#include <iostream>
#include <string>

int main() {
    std::string NumberStr;
    std::cin >> NumberStr;

    int NumLuckyDigits = 0;
    for(const char c : NumberStr) {
        if(c == '4' || c == '7') {
            NumLuckyDigits++;
        }
    }

    bool NearlyLucky = NumLuckyDigits > 0;
    for(const char c : std::to_string(NumLuckyDigits)) {
        if(c != '4' && c != '7') {
            NearlyLucky = false;
        }
    }

    if(NearlyLucky) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }

    return 0;
}