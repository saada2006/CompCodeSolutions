#include <iostream>

int main() {
    int t;
    std::cin >> t;

    int p2[31];
    p2[0] = 1;
    for(int i = 1; i < 31; i++) {
        p2[i] = 2 * p2[i - 1];
    }
    int p3[20];
    p3[0] = 1;
    for(int i = 1; i < 20; i++) {
        p3[i] = 3 * p3[i - 1];
    }

    for(int i = 0; i < t; i++) {
        int n;
        std::cin >> n;


        int d[2] {0, 0}; // 0 - 2, 1 - 3

        for(int i = 0; i < 31; i++) {
            if(n % p2[i] != 0) {
                d[0] = i - 1;
                break;
            }
        }

        for(int i = 0; i < 20; i++) {
            if(n % p3[i] != 0) {
                d[1] = i - 1;
                break;
            }
        }

        int nc = p2[d[0]] * p3[d[1]];
        //std::cout << d[1] << ' ' << nc << ' ';
        if(n == nc && d[0] <= d[1]) {
            int m = d[1] - d[0];
            int g = d[1];
            std::cout << m + g << '\n';
        } else {
            std::cout << -1 << '\n';
        }
    }

    return 0;
}

/*
        bool l[2] {true, true};
        while(l[0] || l[1]) {
            l[0] = l[1] = false;
            if(nc % 2 == 0) {
                nc /= 2;
                l[0] = true;
                d[0]++;
            }
            if(nc % 3 == 0) {
                nc /= 3;
                l[1] = true;
                d[1]++;
            }
        }
*/