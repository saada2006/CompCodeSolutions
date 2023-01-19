#include <iostream>
#include <cstdint>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::int64_t time = 0;
    int prev = 1;
    for(int i = 0; i < m; i++) {
        int curr;
        std::cin >> curr;
        int comp = curr;
        if(comp < prev) {
            comp += n;
        }
        time += comp - prev;
        prev = curr;
    }

    std::cout << time << '\n';
    return 0;
}