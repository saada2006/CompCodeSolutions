#include <iostream>

int main() {
    int n, k;
    std::cin >> n >> k;
    int t = 240 - k;
    int i = 0;
    while(n > 0) {
        n--;
        t -= 5 * (i + 1);
        if(t < 0) {
            break;
        }
        i++;
    }
    std::cout << i << '\n';
    return 0;
}