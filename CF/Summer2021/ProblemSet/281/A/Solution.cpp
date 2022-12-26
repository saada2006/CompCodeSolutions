#include <iostream>
#include <string>

int main() {
    std::string s;
    std::getline(std::cin, s);
    s.front() &= ~32;
    std::cout << s;
}