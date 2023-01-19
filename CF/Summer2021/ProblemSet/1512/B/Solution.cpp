#include <iostream>
#include <string>

int main() {
    int t;
    std::cin >> t;

    for(int i = 0; i < t; i++) {
        int n;
        std::cin >> n;
        std::cin.ignore();

        int x[2], y[2];
        int PointIndex = 0;
        for(int j = 0; j < n; j++) {
            std::string S;
            std::getline(std::cin, S);
            int k = 0;
            for(const char C : S) {
                if(C == '*') {
                    x[PointIndex] = k;
                    y[PointIndex] = j;

                    PointIndex++;
                }
                k++;
            }
        }

        if(x[0] == x[1]) {
            x[1] = (x[1] + 1) % n;
        }

        if(y[0] == y[1]) {
            y[1] = (y[1] + 1) % n;
        }

        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                if((k == x[0] || k == x[1]) && (j == y[0] || j == y[1])) {
                    std::cout << '*';
                } else {
                    std::cout << '.';
                }
            }
            std::cout << '\n';
        }

    }

    return 0;
}