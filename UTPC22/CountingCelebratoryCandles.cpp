#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;

    int c = 0;
    for(char d : s) {
        if(d == '1')
            c++;
    }

    cout << c << '\n';
}