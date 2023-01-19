#include <iostream>
#include <string>

int main() {
    std::string s;
    std::cin >> s;

    std::string a;
    a.reserve(s.size());
    for(const char c : s) {
        a.push_back(c);
        if(a.size() >= 3) {
            if(a.find("WUB", a.size() - 3) != std::string::npos) {
                a.erase(a.size() - 3, 3);
                if(a.size() != 0 && a.back() != ' ') {
                    a.push_back(' ');
                }
            }
        }
    }

    std::cout << a << '\n';

    return 0;
}