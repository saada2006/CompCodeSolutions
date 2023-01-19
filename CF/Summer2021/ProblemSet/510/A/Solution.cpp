#include <iostream>

int main() {
    int n, m;
    std::cin >> n >> m;

    bool After = true;
    for(int i = 0; i < n; i++) {
        if(i % 2 == 0) {
            for(int j = 0; j < m; j++) {
                std::cout << '#';
            }
            std::cout << '\n';
        } else {
            if(!After) {
                std::cout << "#";
            }
            for(int j = 1; j < m; j++) {
                std::cout << '.';
            }
            if(After) {
                std::cout << "#";
            }
            After = !After;
            std::cout << '\n';
        }
    }
}