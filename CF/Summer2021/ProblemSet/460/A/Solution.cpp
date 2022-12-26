#include <iostream>

int main() {
    int n, m;
    std::cin >> n >> m;

    int d = 1;
    while(true) {
        n--;
        if(d % m == 0) {
            n++;
        }
        if(n == 0) {
            std::cout << d << '\n';
            return 0;
        }
        d++;
    }

    std::cout << "Placeholder, uh, how did we get here?\n";
    return -1; 
}