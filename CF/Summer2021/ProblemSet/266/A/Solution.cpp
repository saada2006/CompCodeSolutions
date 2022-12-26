#include <iostream>
#include <string>

int main() {
    int n;
    std::cin >> n;
    std::cin.ignore();
    std::string s;
    s.reserve(n);
    std::getline(std::cin, s);
    char prevcol = '\0';
    int numops = 0;
    for(const char c : s) {
        if(c == prevcol) {
            numops++;
        } else {
            prevcol = c;
        }
    }
    std::cout << numops;
    return 0;
}