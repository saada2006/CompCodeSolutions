#include <iostream>
#include <string>
#include <set>

int main() {
    std::string s;
    std::cin >> s;
    int i = std::stoi(s);

    while(true) {
        i++;
        std::string t = std::to_string(i);
        std::set<int> Digits;
        for(const char c : t) {
            Digits.insert(c);
        }
        if(Digits.size() == t.size()) {
            std::cout << t << '\n';
            return 0;
        }
    }
}