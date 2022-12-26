#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> vec(n);
    for(int& x : vec) {
        std::cin >> x;
    }
    std::sort(vec.begin(), vec.end());
    for(const int x : vec) {
        std::cout << x << ' ';
    }
}