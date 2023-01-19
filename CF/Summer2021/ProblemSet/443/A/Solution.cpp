#include <iostream>
#include <string>
#include <set>

int main() {
    std::string s;
    std::getline(std::cin, s);
    std::set<char> letters;
    for(const char c : s) {
        if(c != ',' && c != ' ' && c != '{' && c != '}') {
            letters.insert(c);
        }
    }
    std::cout << letters.size() << '\n';
    return 0;
}