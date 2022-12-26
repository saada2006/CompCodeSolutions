#include <iostream>
#include <vector>
#include <string>
#include <cstdio>

int main() {
    freopen("cowsignal.in", "r", stdin);
    freopen("cowsignal.out", "w", stdout);

    int m, n, k;
    std::cin >> m >> n >> k;
    std::cin.ignore();

    std::vector<std::string> Signal(m);
    for(std::string& s : Signal) {
        s.reserve(n);
        std::cin >> s;
    }

    int mk = k * m;
    int nk = k * n;

    for(int i = 0; i < mk; i++) {
        for(int j = 0; j < nk; j++) {
            int ik = i / k;
            int jk = j / k;
            std::cout << Signal[ik][jk];
        }
        std::cout << '\n';
    }

    return 0;
}