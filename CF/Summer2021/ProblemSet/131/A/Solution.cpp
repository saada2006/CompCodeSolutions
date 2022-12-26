#include <iostream>
#include <string>
#include <cctype>

int main() {
    std::string s;
    std::cin >> s;

    bool Cond[2] {std::islower(s.front()), true};
    for(int i = 0; i < s.size(); i++) {
        char curr = s[i];
        if(std::islower(curr)) {
            Cond[1] = false;
            if(i != 0) {
                Cond[0] = false;
            }
            if(!Cond[0] && !Cond[1]) {
                break;
            }
        }
    }

    if(Cond[0] || Cond[1]) {
        for(char& c : s) {
            if(std::isupper(c)) {
                c = std::tolower(c);
            } else {
                c = std::toupper(c);
            }
        }
    }

    std::cout << s << '\n';
    return 0;
}