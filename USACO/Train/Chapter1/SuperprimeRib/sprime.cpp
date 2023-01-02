/*
ID: shadax31
LANG: C++
TASK: sprime
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

int n;

vector<int> sols;
void recurse(int x, int d) {
    if(d == n) {
        sols.push_back(x);
    } else {
        for(int i = 1; i <= 9; i += 2) {
            int y = 10 * x + i;
            if(isPrime(y)) recurse(y, d + 1);
        }
    }
}



int main() {
    InitIO("sprime");

    cin >> n;

    recurse(2, 1);
    recurse(3, 1);
    recurse(5, 1);
    recurse(7, 1);

    sort(sols.begin(), sols.end());
    for(int x : sols)
        cout << x << '\n';
}