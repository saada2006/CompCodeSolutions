#include <iostream>
#include <vector>

int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> Fence(n);
    for(int& x : Fence) {
        std::cin >> x;
    }
    int Sum = 0;
    int Min = 100000000;
    int Idx = k - 1;
    for(int i = 0; i < n; i++) {
        if(i < k) {
            Sum += Fence[i];
            Min = Sum;
        } else {
            Sum += Fence[i] - Fence[i - k];
            if(Sum < Min) {
                Min = Sum;
                Idx = i;
            }
        }
    }

    Idx -= k - 2;

    std::cout << Idx << '\n';
    return 0;
}