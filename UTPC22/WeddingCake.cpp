#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int cakes[5];
    fill_n(cakes, 5, 0);

    for(int i = 0; i < n; i++) {
        int l;
        cin >> l;
        l--;
        if(l == 0) {
            cakes[0]++;
        } else if(cakes[l - 1] > 0) {
            cakes[l - 1]--;
            cakes[l]++;
        }
    }

    cout << cakes[4] << '\n';
    
}