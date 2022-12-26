#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int p2 = 0;
    for(int i = 0; i < n; i++) {
        int q;
        cin >> q;
        while(q % 2 == 0) {
            q /= 2;
            p2++;
        }
    }

    cout << p2 << '\n';
}