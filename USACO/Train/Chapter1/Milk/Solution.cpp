/*
ID: shadax31
LANG: C++
TASK: milk
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

int main() {
    InitIO("milk");
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> farmers(m);
    for(auto& p : farmers)
        cin >> p.first >> p.second;
    sort(farmers.begin(), farmers.end());

    int cost = 0;
    for(int i = 0; i < m && n != 0; i++) {
        int bought = min(n, farmers[i].second);
        n -= bought;
        cost += bought * farmers[i].first;
    }

    cout << cost << '\n';
}
