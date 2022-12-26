#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

/*
If the problem statement means one else if is the max, we can brute force this
*/

#define CHKBIT(x, k) ((x & (1 << k)) != 0)

void solve() {
    int n, m;
    cin >> n >> m;

    vector<pair<vector<bool>, bool>> results;
    for(int i = 0; i < m; i++) {
        string s;
        cin >> s;

        vector<bool> input;
        for(char c : s)
            if(c == '1')
                input.push_back(true);
            else  
                input.push_back(false);
        
        int res;
        cin >> res;

        if(res == 1)
            results.emplace_back(input, false);
        else
            results.emplace_back(input, true);
    }

    // case 1: only one index matters
    for(int i = 0; i < n; i++) {
        // bits define what the output is
        for(int bits = 0; bits < 8; bits++) {
            bool work = true;

            for(auto& p : results) {
                bool computed;
                if(p.first[i] == CHKBIT(bits, 0))
                    computed = CHKBIT(bits, 1);
                else
                    computed = CHKBIT(bits, 2);

                if(computed != p.second) {
                    work = false;
                    break;
                }
            }

            if(work) {
                cout << "OK\n";
                return;
            }
        }
    }

    // case 2: two indices matter
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            // bits define what the output is
            for(int bits = 0; bits < 32; bits++) {
                bool work = true;

                for(auto& p : results) {
                    bool computed;
                    if(p.first[i] == CHKBIT(bits, 0))
                        computed = CHKBIT(bits, 1);
                    else if(p.first[j] == CHKBIT(bits, 2))
                        computed = CHKBIT(bits, 3);
                    else
                        computed = CHKBIT(bits, 4);
                    
                    if(computed != p.second) {
                        work = false;
                        break;
                    }
                }

                if(work) {
                    cout << "OK\n";
                    return;
                }
            }
        }
    }

    cout << "LIE\n";

}

int main() {
    

    int t;
    cin >> t;

    while(t--) solve();
}