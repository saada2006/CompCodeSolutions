#include <iostream>
#include <string>
#include <set>
#include <cctype>

int main() {
    int n;
    std::cin >> n;
    std::string s;
    s.reserve(n);
    std::cin >> s;
    std::set<char> letters;
    for(const char c : s) {
        letters.insert(std::tolower(c));
    }
    //for(const char c : letters) {
     //   std::cout << "Lter: " << c << '\n';
   // }
    std::cout << (letters.size() == 26 ? "YES" : "NO") << '\n';
}