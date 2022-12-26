#include <iostream>
#include <utility>

void Sort2(int* ptr) {
    if(ptr[1] > ptr[0]) {
        std::swap(ptr[0], ptr[1]);
    }
}

void solve() {
    int Dim[2][2];

    std::cin >> Dim[0][0] >> Dim[0][1];
    std::cin >> Dim[1][0] >> Dim[1][1];

    Sort2(Dim[0]);
    Sort2(Dim[1]);

    if(Dim[0][0] == Dim[1][0] && Dim[0][0] == Dim[0][1] + Dim[1][1]) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
}

int main() {
    int t;
    std::cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}