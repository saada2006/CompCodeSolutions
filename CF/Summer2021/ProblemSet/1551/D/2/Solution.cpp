#include <iostream>

char Table[100][101];

void print(int n, int m, int k) {
    for(int i = 0; i < n; i++) {
        std::fill_n(Table[i], 101, '\0');
        //Table[i][m] = '\0';
    }

    if(m % 2 == 1) {
        for(int i = 0; i < n; i += 2) {
            Table[i    ][m - 1] = '0';
            Table[i + 1][m - 1] = '0';
        }
    }

    if(n % 2 == 1) {
        for(int i = 0; i < m; i += 2) {
            Table[n - 1][i    ] = '1';
            Table[n - 1][i + 1] = '1';
            k--;
        }
    }

    k/=2;

    int i = 0, j = 0;
    while(k--) {
        if(j >= m) {
            j = 0;
            i += 2;
        }
        Table[i    ][j] = Table[i    ][j + 1] = '1';
        Table[i + 1][j] = Table[i + 1][j + 1] = '1';
        j += 2;
    }

    for(int y = 0; y < n; y++) {
        for(int x = 0; x < m; x++) {
            if(Table[y][x] != '1') {
                Table[y][x] = '0';
            }
        }
    }

    for(int z = 0; z < n; z++) {
        std::cout << Table[z] << '\n';
    }
}

void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;
    int n2 = n, m2 = m, k2 = k;
    int r = (n * m) / 2 - k;

    if(n % 2 == 1) {
        n--;
        k -= m / 2;
    }

    if(k >= 0 && k % 2 == 0) {
        int v = (m % 2) * n / 2;
        if(v + k <= (n * m) / 2) {
            std::cout << "YES\n";
            print(n2, m2, k2);
            return;
        }
    }

    std::cout << "NO\n";
    
}

int main() {
    int t;
    std::cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}