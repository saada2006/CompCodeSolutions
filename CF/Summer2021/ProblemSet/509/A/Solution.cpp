#include <iostream>

int main() {
    int a[10][10];

    for(int i = 0; i < 10; i++) {
        a[0][i] = a[i][0] = 1;
    }

    for(int i = 1; i < 10; i++) {
        for(int j = 1; j < 10; j++) {
            a[i][j] = a[i - 1][j] + a[i][j - 1];
        }
    }

    int idx;
    std::cin >> idx;
    idx--;
    std::cout << a[idx][idx] << '\n';

    return 0;
}