#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> Data(n);
    for(int& x : Data) {
        std::cin >> x;
    }
    std::sort(Data.begin(), Data.end());

    int NumDistinctIntegers = 0;
    int Current = 0;
    for(const int x : Data) {
        if(Current != x) {
            Current = x;
            NumDistinctIntegers++;
        }
    }
    std::cout << NumDistinctIntegers << '\n';

    return 0;
}