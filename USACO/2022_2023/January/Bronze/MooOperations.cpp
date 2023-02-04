#include <iostream>
#include <vector>
#include <string>

using namespace std;

// find the central "o"
void solve() {
    bool found = false;
    int minops = INT32_MAX;

    string s;
    cin >> s;

    for(int i = 1; i < s.length() - 1; i++) {
        if(s[i] == 'O') {
            found = true;

            // delete the first i - 1 characters, and the rest of the characters
            int delf = i - 1;
            int dell = s.length() - i - 2;

            int opssum = delf + dell;
            //cout << i << ' ' << opssum << '\n';
            if(s[i-1] != 'M') {
                opssum++;
            }
            if(s[i+1] != 'O') {
                opssum++;
            }

            minops = min(minops, opssum);
        }
    }

    cout << (found ? minops : -1) << '\n';
}

int main() {
    int q;
    cin >> q;

    while(q--) {
        //cout << "New testcase!\n";
        solve();
    }

    return 0;
}