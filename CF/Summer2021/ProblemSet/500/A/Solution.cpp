#include <iostream>

int main() {
    int n, t;
    std::cin >> n >> t;

    int c = 1;
    for(int i = 1; i < n; i++) {
        int m;
        std::cin >> m;
        for(int j = 1; j < m; j++) {
            int s;
            std::cin >> s;
        }
        c += m;
        if(c == t) {
            std::cout << "YES\n";
            return 0;
        }
    }

    std::cout << "NO\n";
    return 0;
}