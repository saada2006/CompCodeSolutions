/*
ID: shadax31
LANG: C++
TASK: milk3
*/

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <cstdio>
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

set<int> values;

int cap[3];

void pour(int& src, int& dst, int tot) {
    int refill = tot - dst;
    int remain = src;

    int poured = min(refill, remain);

    src -= poured;
    dst += poured;   
}

void recurse(int n, int a, int b, int c) {
    if(n != 0 && a == 0)
        values.insert(c);

    if(n == 13) return;

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            int vol[3];
            vol[0] = a;
            vol[1] = b;
            vol[2] = c;

            if(i == j || vol[i] == 0 || vol[j] == cap[j]) continue;

            pour(vol[i], vol[j], cap[j]);
            recurse(n + 1, vol[0], vol[1], vol[2]);
        }
    }
}

int main() {
    InitIO("milk3");
    cin >> cap[0] >> cap[1] >> cap[2];

    recurse(0, 0, 0, cap[2]);

    int num = 0;
    for(int x : values) {
        cout << x << (num + 1 == values.size() ? '\n' : ' ');
        num++; 
    }
}