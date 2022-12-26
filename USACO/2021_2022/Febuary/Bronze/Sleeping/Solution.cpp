#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> elsie(n);
    int m = 0;
    int s = 0;
    for(int& x : elsie) {
        cin >> x;
        m = max(m, x);
        s += x;
    }

    // in the rare case m is zero:
    if(m == 0 || s == 0) {
        cout << "0\n";
        return;
    }

    int combine = INT32_MAX;

    // find greatest divisor larger than m
    vector<int> sum(n);
    int div = m;
    while(div <= s) {
        if(s % div == 0) {
            copy(elsie.begin(), elsie.end(), sum.begin());
            int current = 0;
            for(int i = 0; i < n - 1; i++) {
                if(sum[i] < div) {
                    sum[i + 1] += sum[i];
                    sum[i] = -1;
                    current++;
                }
            }

            bool valid = true;
            for(int x : sum) {
                if(x != -1 && x != div) {
                    valid = false;
                    break;
                }
            }

            if(valid) {
                combine = min(combine, current);   
            }
        }
        div++;
    }



    cout << combine << '\n';
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}