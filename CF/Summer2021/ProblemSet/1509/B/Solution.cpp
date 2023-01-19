#include <iostream>
#include <string>
#include <algorithm>

void solve() {
    int n;
    std::string s;
    std::cin >> n >> s;

    int k = 0;

    for(const char c : s) {
        if(c == 'T') {
            k++;
        }
    }

    if(k % 2 == 1 || k + k / 2 != n) {
        std::cout << "NO\n";
        return;
    }

    int IdxPosT = 0;
    int IdxPosM = 0;
    for(int i = 0; i < k / 2; i++) {
        while(IdxPosT < n && s[IdxPosT] != 'T') {
            IdxPosT++;
        }
        if(IdxPosT >= n) {
            std::cout << "NO\n";
            return;
        }

        IdxPosM = std::max(IdxPosM, IdxPosT + 1);
        while(IdxPosM < n && s[IdxPosM] != 'M') {
            IdxPosM++;
        }
        IdxPosM++;

        if(IdxPosM >= n) {
            std::cout << "NO\n";
            return;
        }
        IdxPosT++;
    }

    IdxPosT = n - 1;
    IdxPosM = n - 1;
    for(int i = 0; i < k / 2; i++) {
        while(IdxPosT > -1 && s[IdxPosT] != 'T') {
            IdxPosT--;
        }
        if(IdxPosT <= -1) {
            std::cout << "NO\n";
            return;
        }

        IdxPosM = std::min(IdxPosM, IdxPosT - 1);
        while(IdxPosM > -1 && s[IdxPosM] != 'M') {
            IdxPosM--;
        }
        IdxPosM--;

        if(IdxPosM <= -1) {
            std::cout << "NO\n";
            return;
        }
        IdxPosT--;
    }

    std::cout << "YES\n";
}

int main() {
    int t;
    std::cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}