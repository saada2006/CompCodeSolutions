/*
ID: shadax31
LANG: C++
TASK: palsquare
*/

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <cstdio>
using namespace std;
void InitIO(const char* FileName) {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    
    constexpr std::size_t BufferSize = 256;
    char StrBuf[BufferSize];

    StrBuf[0] = '\0';
    std::snprintf(StrBuf, BufferSize, "%s.in", FileName);
    std::freopen(StrBuf, "r", stdin);

    StrBuf[0] = '\0';
    std::snprintf(StrBuf, BufferSize, "%s.out", FileName);
    std::freopen(StrBuf, "w", stdout);    
}

char get_digit(int r) {
    if(r < 10)
        return '0' + r;
    else   
        return 'A' + r - 10;
}

string get_base(int b, int i) {
    string rep;

    while(i != 0) {
        int r = i % b;
        i /= b;

        rep = get_digit(r) + rep;
    }

    return rep;
}

int main() {
    InitIO("palsquare");

    int b;
    cin >> b;

    for(int i = 1; i <= 300; i++) {
        int i2 = i * i;

        string bi = get_base(b, i);
        string bi2 = get_base(b, i2);

        string bi2r = bi2;
        reverse(bi2.begin(), bi2.end());
        if(bi2 == bi2r)
            cout << bi << ' ' << bi2 << '\n';
    }
}