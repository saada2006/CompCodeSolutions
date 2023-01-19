#include <iostream>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    int numpassen = 0;
    int mincap = 0;

    for(int i = 0; i < n; i++) {
        int a, b;
        std::cin >> a >> b;
        numpassen += b;
        numpassen -= a;
        mincap = std::max(mincap, numpassen);
    }

    std::cout << mincap;
}