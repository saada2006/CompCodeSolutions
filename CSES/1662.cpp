#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int main() {
    ll n;
    cin >> n;

    vector<ll> a(n);
    vector<ll> m(n);

    ll prev = 0;
    ll narr = 0;


    for(auto& x : a) {
        cin >> x;
        x %= n;

        if(x < 0) {
            x += n;
        }

        x += prev;
        x %= n;

        if(x == 0) {
            narr++;
        }

        if(x < 0 || x >= n) {
            cout << "uhoh!" << x % n;
            return 0;
        }

        // substract mod
        narr += m[x];

        m[x]++;
        prev = x;
    }

    cout << narr << '\n';
}