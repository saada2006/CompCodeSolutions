#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int64_t> c(n);
    for(auto& x : c)
        cin >> x;

    sort(c.begin(), c.end());

    int64_t best_tution = c[0];
    int64_t max_profit = best_tution * n;
    
    int64_t prev_val = c[0];
    for(int i = 0; i < c.size(); i++, n--) {
        // skip to next unique val
        while(i < c.size() && c[i] == prev_val) {
            i++;
            n--;
        }
        
        if(i == c.size())
            break;
        
        int64_t current_tution = c[i];
        int64_t current_profit = current_tution * n;

        if(current_profit > max_profit) {
            best_tution = current_tution;
            max_profit = current_profit;
        }

        prev_val = current_tution;
    }

    cout << max_profit << ' ' << best_tution << '\n';

}