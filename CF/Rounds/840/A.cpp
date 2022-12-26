#include <iostream>

using namespace std;

void solve() {
    int n; 
    cin >> n;

    int max = 0;
    int min = 2047;

    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;

        max |= x;
        min &= x;
    }

    cout << max - min << '\n';
}

int main() {
    int t;
    cin >> t;

    while(t--) solve();
}