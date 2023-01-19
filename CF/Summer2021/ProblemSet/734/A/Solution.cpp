#include <iostream>
#include <string>

int main() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;

    int Wins[2] {0, 0};
    for(int i = 0; i < n; i++) {
        if(s[i] == 'D') {
            Wins[1]++;
        } else {
            Wins[0]++;
        }
    }

    std::cout << (Wins[1] == Wins[0] ? "Friendship" : (Wins[1] > Wins[0] ? "Danik" : "Anton")) << '\n';
    return 0;
}