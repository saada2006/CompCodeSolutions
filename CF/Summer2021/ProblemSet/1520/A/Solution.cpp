#include <iostream>
#include <string>
#include <set>

int main() {
    int t;
    std::cin >> t;

    for(int i = 0; i < t; i++) {
        int n;
        std::cin >> n;
        std::string s;
        s.reserve(n);
        std::cin >> s;
        std::set<char> Tasks;
        char Previous = '\0';
        bool Yes = true;
        for(const char c : s) {
            if(c != Previous && Tasks.count(c) == 1) {
                Yes = false;
                break;
            }
            Tasks.insert(c);
            Previous = c;
        }
        std::cout << (Yes ? "YES\n" : "NO\n");
    }
    return 0;
}