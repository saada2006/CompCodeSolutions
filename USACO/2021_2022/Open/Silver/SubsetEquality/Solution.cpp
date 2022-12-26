#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

constexpr size_t hsize = 'r' - 'a' + 1;

int main() {
    string r, l;

    cin >> r >> l;

    uint64_t rhash[hsize], lhash[hsize];
    uint64_t rmult[hsize], lmult[hsize];

    fill_n(rhash, hsize, 0);
    fill_n(lhash, hsize, 0);

    fill_n(rmult, hsize, 1);
    fill_n(lmult, hsize, 1);

    // build the hash
    int n = r.size();
    constexpr uint64_t a = 3;
    for(int i = n - 1; i >= 0; i--) {
        uint64_t cr = r[i];
        uint64_t cl = l[i];

        int ir = cr - 'a';
        int il = cl - 'a';

        rhash[ir] += cr * rmult[ir];
        lhash[il] += cl * lmult[il];

        rmult[ir] *= a;
        lmult[il] *= a;
    }

    int k;
    cin >> k;

    for(int i = 0; i < k; i++) {
        uint64_t rsum = 0, lsum = 0;
        string q;
        cin >> q;

        for(char cq : q) {
            rsum += rhash[cq - 'a'];
            lsum += lhash[cq - 'a'];
        }

        //cout << (rsum == lsum ? 'Y' : 'N');
        cout << rsum << ' ' << lsum << '\n';
    }

    return 0;
}