#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> Gift(n);
    for(int i = 1; i <= n; i++) {
        int j;
        std::cin >> j;
        Gift[j - 1] = i;
    }
    for(const int x : Gift) {
        std::cout << x << ' ';
    }
    std::cout << '\n';

    return 0;
}