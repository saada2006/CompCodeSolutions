#include <iostream>
#include <string>

using namespace std;

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    int q = 0;

    for(char c : s) {
        if(c == 'Q')
            q++;
        else if(c == 'A' && q > 0)
            q--;
    }

    cout << (q == 0 ? "Yes" : "No") << '\n';
}

int main() {
    int t;
    cin >> t;

    while(t--)
        solve();
}