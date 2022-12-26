#include <iostream>
#include <string>

int main() {
    int t;
    std::cin >> t;

    for(int i = 0; i < t; i++) {
        std::string s;
        std::cin >> s;
        char max = '0';
        for(const char c : s) {
            if(c > max) {
                max = c;
            }
        }
        std::cout << max - '0' << '\n';
    }

    return 0;
}