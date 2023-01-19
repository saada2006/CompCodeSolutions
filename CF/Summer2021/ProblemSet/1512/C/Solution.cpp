#include <iostream>
#include <string>

void solve() {
    int a, b, c = 0;
    std::string s;
    std::cin >> a >> b >> s;

    int I = 0, J = s.length() - 1;
    while(I < J) {
        char& L = s[I];
        char& R = s[J];

        if(L == R && L == '?') {
            c++;
        } else if(L != R && ((L == '1' && R == '?') || (L == '?' && R == '1'))) {
            s[I] = s[J] = '1';
        } else if(L != R && ((L == '0' && R == '?') || (L == '?' && R == '0'))) {
            s[I] = s[J] = '0';
        } else if(L != R && L != '?' && R != '?') {
            std::cout << -1 << '\n';
            return;
        }

        if(L == '0') {
            a -= 2;
        }

        if(L == '1') {
            b -= 2;
        }

        I++;
        J--;
    }

    if(I == J && s[I] == '?') {
        if(a % 2 == 1) {
            s[I] = '0';
        } else {
            s[I] = '1';
        }
    }

    if(I == J) {
        if(s[I] == '0') {
            a--;
        } else {
            b--;
        }
    }

    if(a + b == 2 * c && a >= 0 && b >= 0 && a % 2 == 0 & b % 2 == 0) {
        I = 0;
        J = s.length() - 1;

        while(I < J) {
            if(s[I] == '?') {
                if(a > 0) {
                    s[I] = s[J] = '0';
                    a -= 2;
                } else {
                    s[I] = s[J] = '1';
                    b -= 2;
                }
            }

            I++;
            J--;
        }

        if(a == 0 && b == 0) {
            std::cout << s << '\n';
            return;
        }
    }

    std::cout << -1 << '\n';

}

int main() {
    int t;
    std::cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}