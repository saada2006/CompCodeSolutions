#include <iostream>
#include <string>

int main() {
    std::string s;
    std::cin >> s;
    for(const char c : s) {
        if(c == 'H' || c == 'Q' || c == '9') {
            std::cout << "YES\n";
            return 0;
        }
    }
    std::cout << "NO\n";
    return 0;
}