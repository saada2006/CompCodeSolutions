#include <iostream>
#include <string>
#include <vector>
#include <cstdio>

int main() {
    freopen("word.in", "r", stdin);
    freopen("word.out", "w", stdout);

    int n, k;
    std::cin >> n >> k;
    std::cin.ignore();

    std::vector<std::string> Essay(n);
    for(auto& s : Essay) {
        s.reserve(16);
        std::cin >> s;
        s.push_back(' ');
    }

    int AccumLength = 0;
    for(auto Iter = Essay.begin(); Iter != Essay.end(); Iter++) {
        AccumLength += Iter->length() - 1;
        if(AccumLength > k) {
            (Iter - 1)->back() = '\n';
            AccumLength = Iter->length() - 1;
        }
        if(Iter + 1 == Essay.end()) {
            Iter->back() = '\n';
        }
    }

    for(const auto& s : Essay) {
        std::cout << s;
    }

    return 0;
}