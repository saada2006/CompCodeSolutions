#include <iostream>
#include <vector>
#include <string>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::string Source;
    Source.reserve(n);
    std::cin >> Source;

    

    for(int i = 0; i < m; i++) {
        int l, r;
        std::cin >> l >> r;
        l--; r--;

        int Modifications = 0;
        while(l < r) {
            if(Source[l] != Source[r]) {
                Modifications++;
            }
            l++;
            r--;
        }

        std::cout << Modifications << '\n';
    }
}