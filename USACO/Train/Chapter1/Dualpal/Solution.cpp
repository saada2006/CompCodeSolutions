/*
ID: shadax31
LANG: C++
TASK: dualpal
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

bool palindrome(int b, int i) {
    string rep = get_base(b, i);
    string repr = rep;
    reverse(repr.begin(), repr.end());

    return (rep == repr);
}

int main() {
    InitIO("dualpal");

    int n, s;

    cin >> n >> s;

    for(int i = s + 1; n > 0; i++) {
        int c = 0;
        for(int b = 2; b <= 10; b++)
            if(palindrome(b, i))
                c++;
        if(c >= 2) {
            n--;
            cout << i << '\n';
        }
    }
}