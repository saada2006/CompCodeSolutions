#include <iostream>
#include <string>

int main() {
    std::string t;
    std::cin >> t;

    for(int i = 0; i < 5; i++) {
        std::string h;
        std::cin >> h;

        if(t[0] == h[0] || t[1] == h[1]) {
            std::cout << "YES\n";
            return 0;
        }
    }

    std::cout << "NO\n";
    return 0;
}