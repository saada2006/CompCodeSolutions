#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> Numbers(n);
    for(int& x : Numbers) {
        std::cin >> x;
    }

    // Check how many of the first 3 are even
    int Parity = 0;
    Parity += (Numbers[0] % 2 == 0);
    Parity += (Numbers[1] % 2 == 0);
    Parity += (Numbers[2] % 2 == 0);
    int ExpectedMod = Parity >= 2 ? 0 : 1;

    for(int i = 0; i < n; i++) {
        if(Numbers[i] % 2 != ExpectedMod) {
            std::cout << i + 1 << '\n';
            break;
        }
    }

    return 0;
}