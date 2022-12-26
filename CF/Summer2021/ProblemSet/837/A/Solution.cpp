#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>

int main() {
    int n;
    std::cin >> n;
    std::cin.ignore();
    std::string s;
    std::getline(std::cin, s);

    int MaxVolume = 0;
    int CurVolume = 0;
    for(int i = 1; i <= n; i++) {
        char c = s[i - 1];
        if(std::isupper(c))
            CurVolume++;
        if(c == ' ' || i == n) {
            MaxVolume = std::max(MaxVolume, CurVolume);
            CurVolume = 0;
        }
    }

    std::cout << '\n' << MaxVolume << '\n';
}