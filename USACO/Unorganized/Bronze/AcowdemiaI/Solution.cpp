#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, l;
    std::cin >> n >> l;
    std::vector<int> Citations(n);
    for(int& x : Citations) {
        std::cin >> x;
    }
    std::sort(Citations.rbegin(), Citations.rend());

    int HIndex = 0;
    int HPos = 0;
    for(int i = 0; i < n; i++) {
        if(Citations[i] >= i + 1) {
            HIndex++;
            HPos = i;
        } else {
            break;
        }
    }

    if(HIndex == n) {
        std::cout << HIndex << '\n';
        return 0;
    }

    int NextH = HIndex + 1;
    int Increase = 0; 
    for(int i = 0; i < NextH; i++) {
        int Val = Citations[i];
        if(Val < NextH) {
            int Diff = NextH - Val;
            if(Diff > 1) {
                Increase = l + 1;
                break;
            } else {
                Increase += Diff;
            }
        }
    }

    std::cout << (Increase > l ? HIndex : NextH) << '\n';

    return 0;
}