/*
ID: shadax31
LANG: C++
TASK: barn1
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
    InitIO("barn1");
    int m, s, c;
    cin >> m >> s >> c;

    // s doesn't matter lol

    vector<int> locations(c);
    for(int& x : locations)
        cin >> x;
    sort(locations.begin(), locations.end());

    int pos = locations[0];

    vector<int> dist;
    for(int i = 1; i < c; i++) {
        int nextpos = locations[i];
        dist.push_back(nextpos - pos - 1);
        pos = nextpos;
    }

    sort(dist.begin(), dist.end());

    int boards = c;
    int total_length = c;
    int i = 0;
    while(boards > m) {
        total_length += dist[i];
        i++;
        boards--;
    }

    cout << total_length << '\n';
}