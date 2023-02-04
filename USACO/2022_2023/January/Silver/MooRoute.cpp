#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    int t = 0;
    vector<int> crosses(n);
    for(int& x : crosses) {
        cin >> x;
        t += x;
    }

    string path;
    path.reserve(t);
    int pos = 0;
    for(int i = 0; i < t; i++) {
        // to minimize dir changes, go all the way right
        while(pos < n && crosses[pos] > 0) {
            i++;

            crosses[pos]--;
            pos++;
            path.push_back('R');
        }

        // now go all the way back
        bool remaining = false;
        while(pos > 0) {
            i++;

            pos--;
            if(crosses[pos] > 1) {
                if(remaining) {
                    // must go back and finishing remaining now
                    pos++;
                    break;
                } else {
                    remaining = true;
                }
            }

            crosses[pos]--;
            path.push_back('L');
        }

        if(pos == -1) {
            pos = 0;
        }
    }

    cout << path << '\n';

}