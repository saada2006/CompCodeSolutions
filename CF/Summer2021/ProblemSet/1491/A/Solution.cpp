#include <iostream>
#include <vector>

int main() {
    int n, q;
    std::cin >> n >> q;

    std::vector<int> Elems(n);
    int num1 = 0;
    for(int& x : Elems) {
        std::cin >> x;
        num1 += x;
    }

    for(int i = 0; i < q; i++) {
        int t;
        std::cin >> t;
        if(t == 1) {
            int x;
            std::cin >> x;
            x--;
            int& a = Elems[x];
            if(a == 1) {
                num1--;
                a = 0;
            } else {
                num1++;
                a = 1;
            }
        } else {
            int k;
            std::cin >> k;
            k--;
            if(k < num1) {
                std::cout << "1\n";
            } else {
                std::cout << "0\n";
            }
        }
    }

    return 0;
}