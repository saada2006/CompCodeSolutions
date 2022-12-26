#include <iostream>
#include <algorithm>

using namespace std;

// Note that the sum of partions is in of itself an alternating sum
// p n p | p n p   if alt sum of partions (p n p) - (n p n)
// 
// Now, we can do this prefix sum style:
// prefix sum of [l, r] inclusive is p_r - p_(l - 1)
// The sum then

void solve() {
    int n;
    cin >> n;

    if(n == -1) {
        cout << "-1\n";
        return;
    }

    vector<int> arr(n);
    for(int& x : arr)
        cin >> x;

    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) {
        if(i % 2 == 0){
            a[i] = arr[i];
            b[i] = -arr[i];
        } else {
            a[i] = -arr[i];
            b[i] = arr[i];
        }
    }


}

int main() {
    int t;
    cin >> t;

    while(t--)
        solve();
}