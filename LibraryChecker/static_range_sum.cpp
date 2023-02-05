#include <vector>
#include <iostream>

using namespace std;

typedef long long ll;

int main() {
    int n, q;
    cin >> n >> q;

    vector<ll> a(n);
    for(ll& x : a) {
        cin >> x;
    }

    vector<ll> prefix(n + 1);
    prefix[0] = 0;
    for(int i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] + a[i];
    }

    for(int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        cout << prefix[r] - prefix[l] << '\n';
    }
}