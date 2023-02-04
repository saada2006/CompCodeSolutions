#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<int> e(n);
    for(int& x : e) {
        cin >> x;
    }

    // does g have an all includer
    bool gall = true, hall = true;

    int gidx = s.find_first_of('G');
    for(int i = e[gidx]; i < n; i++) {
        if(s[i] == 'G') {
            gall = false;
            //gidx = n + 1;
            break;
        }
    }

    int hidx = s.find_first_of('H');
    for(int i = e[hidx]; i < n; i++) {
        if(s[i] == 'H') {
            hall = false;
            //hidx = n + 1;
            break;
        }
    }

    int numpairs = 0;

    if(gall && hall) {
        numpairs++;
    }

    // iterate over all possible pairs to see if it is included
    for(int i = 0; i < n; i++) {
        int upto = e[i];
        if(s[i] == 'G' && hall) {
            if(i == gidx && gall) {
                continue; // don't over count
            }

            if(i < hidx && hidx < upto) {
                numpairs++;
                //cout << i << '\n';
            }
        } else if(s[i] == 'H' && gall) {
            if(i == hidx && hall) {
                continue; // don't over count
            }

            if(i < gidx && gidx < upto) {
                numpairs++;
                //cout << i << '\n';

            }
        }
    }

    cout << numpairs << '\n';
}