#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t, k;
    cin >> t >> k;

    vector<int> skittles;
    while(true) {
        int x;
        cin >> x;
        if(cin.fail()){
            break;
        }
        skittles.push_back(x);
    }
    sort(skittles.begin(), skittles.end());

    int n = skittles.size();
    int i = distance(skittles.begin(), lower_bound(skittles.begin(), skittles.end(), t));
    int s = 0;
    for(int j = 0; j < k && j + i < n; j++) {
        s += skittles[i + j];
    }

    cout << s << '\n';

}