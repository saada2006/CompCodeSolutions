#include <iostream>

int main() {
    int n;
    std::cin >> n;
    int ng = 0;
    char prev = '\0';
    std::string s;
    s.reserve(2);
    for(int i = 0; i < n; i++) {
        std::cin >> s;
        if(s[0] == prev || i == 0) {
            ng++;
        } 
        prev = s[1];
    }
    std::cout << ng << '\n';
    return 0;
}