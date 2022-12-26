#include <iostream>
#include <string>

int main() {
    std::string s;
    std::getline(std::cin, s);

    char prevchar = '\0';
    int numplayers;

    for(const char c : s) {
        if(c == prevchar) {
            numplayers++;
            if(numplayers == 7) {
                std::cout << "YES";
                return 0;
            }
        } else {
            numplayers = 1;
            prevchar = c;
        }
    }

    std::cout << "NO";
    return 0;
}