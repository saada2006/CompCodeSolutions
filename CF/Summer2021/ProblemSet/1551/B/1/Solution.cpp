#include <iostream>
#include <string>

int Freq[26];

void solve() {
    std::string s;
    std::cin >> s;

    std::fill_n(Freq, 26, 0);

    for(const char c : s) {
        Freq[c - 'a']++;
    }

    int RG = 0, C = 0;
    for(int i = 0; i < 26; i++) {
        if(Freq[i] == 1) {
            C++;
        } else if(Freq[i] != 0) {
            RG++;
        }
    }

    RG += C / 2;
    std::cout << RG << '\n';
}

int main() {
    int t;
    std::cin >> t;

    for(int i = 0; i < t; i++) {
        solve();
    }

    return 0;
}