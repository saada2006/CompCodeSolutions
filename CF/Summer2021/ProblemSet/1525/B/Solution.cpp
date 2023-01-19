#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    int t;
    std::cin >> t;

    for(int i = 0; i < t; i++) {
        int n;
        std::cin >> n;

        std::vector<int> Data(n);
        for(int& x : Data) {
            std::cin >> x;
        }

        if(std::is_sorted(Data.begin(), Data.end())) {
            std::cout << "0\n";
        } else if (Data.back() == n) {
            std::cout << "1\n";
        } else {
            std::cout << "2\n";
        }// should consider 3 case
    }
}