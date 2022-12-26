/*
ID: shadax31
LANG: C++
TASK: skidesign
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

int main() {
    InitIO("skidesign");

    int n;
    cin >> n;

    vector<int> hills(n);
    for(int& x : hills)
        cin >> x;
    
    //sort(hills.begin(), hills.end());

    int bestc = INT32_MAX;
    for(int h = 0; h <= 83; h++) {
        int u = h + 17;
        int cost = 0;
        for(int x : hills) {
            if(h <= x && x <= u)
                continue;
            int diff;

            if(x < h)
                diff = h - x;
            else
                diff = x - u;
            cost += diff * diff;
        }
        if(cost < bestc) {
            bestc = cost;
        }
    }

    cout << bestc << '\n';
}