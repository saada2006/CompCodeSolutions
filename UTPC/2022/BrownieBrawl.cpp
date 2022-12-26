#include <iostream>

using namespace std;

int64_t mod = 1000000007;

int main() {
    int n;
    cin >> n;

    n -= 2;

    int64_t a, b;
    cin >> a >> b;
    cout << a << ' ' << b << ' ';

    for(int i = 0; i < n; i++) {
        int64_t c;
        cin >> c;

        // since modular arithmetic is repeated addition
        // we can write ab mod m = (sum b mod m) mod m
        // this boils down to (a * (b mod m)) mod m
        int64_t d = (a + b) % mod;
        int64_t e = (c * d) % mod;
        
        cout << e << ' ';

        a = b;
        b = e;
    }

}
