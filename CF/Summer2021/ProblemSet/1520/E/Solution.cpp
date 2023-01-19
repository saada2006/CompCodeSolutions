#include <iostream>
#include <string>
#include <algorithm>

void solve() {
    int n;
    std::string s;
    std::cin >> n >> s;

    int NumSheep = 0;
    for(const char c : s) {
        if(c == '*') {
            NumSheep++;
        }
    }

    if(NumSheep == 0 || NumSheep == 1) {
        std::cout << "0\n";
        return;
    }

    int Median = (NumSheep + 1) / 2;

    int NumSheepSeen = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == '*') {
            NumSheepSeen++;
        }

        if(NumSheepSeen == Median) {
            std::int64_t MinMoves = 0;
            int L = i - 1, R = i + 1;

            for(int j = i - 1; j > -1; j--) {
                if(s[j] == '*') {
                    MinMoves += L - j;
                    L--;
                }
            }

            for(int j = i + 1; j < n; j++) {
                if(s[j] == '*') {
                    MinMoves += j - R;
                    R++;
                }
            }

            std::cout << MinMoves << '\n';
            return;
        }
    }
}

int main() {
    int t;
    std::cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}