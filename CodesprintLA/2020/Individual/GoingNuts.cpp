#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int digits = 0;
    for(int i = 0; i < 32; i++) {
        if(n & (1 << i))
            digits++;
    }

    cout << digits << '\n';
}