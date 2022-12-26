/*
ID: shadax31
LANG: C++
TASK: combo
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

int n;

int lock_dist(int i, int c) {
    int dist0 = abs(c - i);
    int dist1 = abs(c - (i + n));
    int dist2 = abs(c - (i - n));
    return min(dist0, min(dist1, dist2));
}

bool valid_combo(int i, int j, int k, int* c) {
    return (
        lock_dist(i, c[0]) <= 2 &&
        lock_dist(j, c[1]) <= 2 &&
        lock_dist(k, c[2]) <= 2
    );
}

int main() {
    InitIO("combo");

    cin >> n;

    int c[2][3];

    for(int i = 0; i < 2; i++) 
        for(int j = 0; j < 3; j++)
            cin >> c[i][j];
    
    int sols = 0;
    for(int i = 1; i <= n; i++) 
        for(int j = 1; j <= n; j++)
            for(int k = 1; k <= n; k++)
                if(valid_combo(i, j, k, c[0]) || valid_combo(i, j, k, c[1]))
                    sols++;

    cout << sols << '\n';
}