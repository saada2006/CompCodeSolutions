#include <iostream>
#include <algorithm>

int main() {
    int col[4];
    std::cin >> col[0] >> col[1] >> col[2] >> col[3];
    std::sort(col, col + 4);
    int ans = 0;
    for(int i = 0; i < 3; i++) {
        if(col[i] == col[i + 1]) {
            ans++;
        }
    }
    std::cout << ans << '\n';
    return 0;
}