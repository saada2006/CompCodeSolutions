#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> a(n), b(n);
    for(auto& x : a) cin >> x;
    for(auto& x : b) cin >> x;

    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());

    long long configurations = 1;
    for(int i = 0; i < n; i++) {
        int stalls = 0;
        while(b[stalls] >= a[i]) {
            stalls++;
        }

        configurations *= (stalls - i);
    }

    cout << configurations << '\n';

}