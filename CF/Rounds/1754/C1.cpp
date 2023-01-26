#include <iostream>
#include <vector>
 
using namespace std;
 
 
void solve() {
    int n;
    cin >> n;
 
    int cursum = 0;
 
    vector<int> a(n);
    for(int& x : a) {
        cin >> x;
        cursum += x;
    }
 
    if(n % 2 == 1) {
        cout << "-1\n";
        return;
    }
 
    vector<pair<int, int>> segments;
 
    // iterate, does combining the next element into an alternating sum decrease the cursum?
 
    for(int i = 0; i < n; i += 2) {
        int combsum = cursum;
        combsum -= 2 * a[i + 1]; // subtract once to get rid of original summation, then again for alt sum
 
        // we can be inefficient with our segments - worst case we have 200000 segments
        if(abs(combsum) < abs(cursum)) {
            // combine!
            segments.emplace_back(i, i + 1);
            cursum = combsum;
        } else {
            segments.emplace_back(i, i);
            segments.emplace_back(i + 1, i + 1);
        }
    }
 
    if(cursum != 0) {
        cout << "uhoh\n";
    }
 
    cout << segments.size() << '\n';
    for(auto p : segments) {
        cout << p.first + 1 << ' ' << p.second + 1 << '\n';
    }
}
 
int main() {
    int t;
    cin >> t;
 
    while(t--) solve() ;
 
    return 0;
}