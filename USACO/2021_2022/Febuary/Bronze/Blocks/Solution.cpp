#include <vector>
#include <string>
#include <iostream>
#include <set>
#include <algorithm>
#include <array>

using namespace std;
int main() {
    int n;
    cin >> n;

    set<char> blocks[4];
    for(int i = 0; i < 4; i++) {
        string s;
        cin >> s;
        for(char c : s) {
            blocks[i].insert(c);
        }
    }

    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        bool yes = false;

        array<int, 4> order = {0, 1, 2, 3};
        do {
            bool cond = true;
            for(int j = 0; j < s.size(); j++) {
                cond &= (blocks[order[j]].count(s[j]) == 1);
            }
            yes |= cond;
        } while(next_permutation(order.begin(), order.end()));

        cout << (yes ? "YES" : "NO") << '\n';
    }
}