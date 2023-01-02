/*
ID: shadax31
LANG: C++
TASK: pprime
*/

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <cstdio>
#include <math.h>
using namespace std;
void InitIO(const char* FileName) {
    #ifndef ONLINE_JUDGE
    std::cin.tie(nullptr)->sync_with_stdio(false);
    
    constexpr std::size_t BufferSize = 256;
    char StrBuf[BufferSize];

    StrBuf[0] = '\0';
    std::snprintf(StrBuf, BufferSize, "%s.in", FileName);
    std::freopen(StrBuf, "r", stdin);

    StrBuf[0] = '\0';
    std::snprintf(StrBuf, BufferSize, "%s.out", FileName);
    std::freopen(StrBuf, "w", stdout);   
    #endif 
}

bool isPrime(int x) {
    int ub = 1 + (int)sqrt(x);
    for(int i = 3; i <= ub; i++) 
        if(x % i == 0) 
            return false;   

    return true;
}

int fastReverse(int x) {
    int y = 0;
    while(x != 0) {
        y *= 10;
        int r = x % 10;
        x /= 10;
        y += r;
    }
    return y;
}

int firstDigit(int x) {
    int r = 0;

    while(x != 0) {
        r = x % 10;
        x /= 10;
    }

    return r;
}

int getMult(int x) {
    int mult = 1;
    while(x != 0) {
        mult *= 10;
        x /= 10;
    }
    return mult;
}

int main() {
    InitIO("pprime");

    int a, b;
    cin >> a >> b;                    
    vector<int> sols;

    if(a <= 5 && 5 <= b) cout << "5\n";
    if(a <= 7 && 7 <= b) cout << "7\n";

    for(int i = 1; i <= 9999; i++) {
        if(firstDigit(i) % 2 == 0) continue;

        int mult = getMult(i);
        int rev = fastReverse(i);

        if(i % 10 != 0) {
            int numE = mult * i + rev;
            
            if(a <= numE && numE <= b && isPrime(numE)) 
                sols.push_back(numE);
        }

        for(int j = 0; j <= 9; j++) {
            int numO = mult * (10 * i + j) + rev;
            if(a <= numO && numO <= b && isPrime(numO)) 
                sols.push_back(numO);
        }

    }

    sort(sols.begin(), sols.end());
    for(int x : sols)
        cout << x << '\n';
}