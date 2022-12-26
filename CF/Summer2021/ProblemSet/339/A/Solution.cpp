#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::string s;
    std::getline(std::cin, s);

    std::sort(s.begin(), s.end());

    for(int Idx = (s.length() - 1) / 2; Idx < s.length(); Idx++) {
        std::cout << s[Idx];
        if(Idx + 1 != s.size()) {
            std::cout << '+';
        }
    }

    return 0;
}