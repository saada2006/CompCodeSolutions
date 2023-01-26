#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> freq(x + 1);
    fill(freq.begin(), freq.end(), 0);

    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        freq[x]++;
    }

    for(int i = 1; i < x; i++) { // up to x, not at x - we don't care about anything x and above
        if(freq[i] == 0)
            continue;
        
        int req = i + 1;
        if(freq[i] % req == 0) {
            freq[i + 1] += freq[i] / req;
        } else {
            cout << "No\n";
            return 0;
        }


    }

    cout << "Yes\n";
    return 0;
}