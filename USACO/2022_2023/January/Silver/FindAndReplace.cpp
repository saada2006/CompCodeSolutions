#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve() {
    string a, b;
    cin >> a >> b;

    if(a.length() != b.length()) {
        cout << -1 << '\n';
        return;
    }

    

    int ops = 0;
    bool good = true;
    map<char, char> changes;

    for(int i = 0; i < a.length(); i++) {
        if(a[i] == b[i] && changes.count(a[i]) == 1) {
            // okay, can we fix the tranasformation by hotswapping to a different letter before? 
        }
    }
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}