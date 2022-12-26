#include <iostream>
#include <string>

int main() {
    int n;
    std::cin >> n;
    bool Idx = n % 2 == 0;
    std::string msg = Idx ? "I love it" : "I hate it";
    std::string c[2] {"I hate that ", "I love that "};
    for(int i = 1; i < n; i++) {
        Idx = !Idx;
        msg = c[Idx] + msg;
    }
    std::cout << msg << '\n';
    return 0;
}