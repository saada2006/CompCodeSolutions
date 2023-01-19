#include <iostream>
#include <string>
#include <set>

int main() {
    std::string s;
    std::getline(std::cin, s);
    std::set<char> DistinctChars;
    for(const char c : s) {
        DistinctChars.insert(c);
    }
    std::cout << (DistinctChars.size() % 2 == 1 ? "IGNORE HIM!" : "CHAT WITH HER!");
}