#include <iostream>
#include <iomanip>

int main() {
    int n;
    std::cin >> n;
    double volpct = 0.0;
    for(int i = 0; i < n; i++) {
        int j;
        std::cin >> j;
        volpct += j;
    }
    std::cout << std::setprecision(1024) << volpct / n << '\n';
    return 0;
}