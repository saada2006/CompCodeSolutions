#include <iostream>
#include <string>

int main() {
    std::string s;
    std::getline(std::cin, s);

    int Upper = 0, Lower = 0;
    for(const char c : s) {
        if((c & 32) == 0) {
            Upper++;
        } else {
            Lower++;
        }
    }

    for(char& c : s) {
        if(Upper > Lower) {
            c &= ~32;
        } else {
            c |= 32;
        }
    }

    std::cout << s;

    return 0;
}