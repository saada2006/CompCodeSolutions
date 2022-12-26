#include <iostream>
#include <vector>

int main() {
    int n, x;
    std::cin >> n >> x;
    std::vector<int> Nuts(n);
    for(int& x : Nuts) {
        std::cin >> x;
    }
    int k;
    std::cin >> k;
    int NumNuts = 0;
    for(int i = 0; i < k; i++) {
        int j;
        std::cin >> j;
        NumNuts += Nuts[--j];
    }

    std::cout << x - NumNuts + 1 << '\n';
}