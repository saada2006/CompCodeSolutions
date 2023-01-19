#include <iostream>
#include <algorithm>

int Search(int n, int a, int b, int c, int l = 0, int p = 0) {
    if(l > n) {
        return -1;
    } else if(l == n) {
        return p;
    } else {
        p++;
        return std::max(Search(n, a, b, c, l + a, p), std::max(Search(n, a, b, c, l + b, p), Search(n, a, b, c, l + c, p)));
    }
}

int main() {
    int n, a, b, c;
    std::cin >> n >> a >> b >> c;
    
    int s = 0;
    int l[3] {0, 0, 0};
    int p[3] {0, 0, 0};
    while(l[0] <= n) {
        p[1] = 0;
        l[1] = 0;
        while(l[0] + l[1] <= n) {
            l[2] = n - (l[0] + l[1]);
            p[2] = l[2] / c;
            if(l[2] % c == 0) {
                s = std::max(s, p[0] + p[1] + p[2]);
            }
            p[1]++;
            l[1] += b;
        }
        p[0]++;
        l[0] += a;
    }
    std::cout << s << '\n';
    return 0;
}