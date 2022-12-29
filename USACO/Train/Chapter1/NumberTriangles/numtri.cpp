/*
ID: shadax31
LANG: C++
TASK: numtri
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

// easy with dp

int main() {
    InitIO("numtri");
    int r;
    cin >> r;

    vector<vector<int>> tri;
    vector<vector<int>> max_score;

    for(int i = 1; i <= r; i++) {
        vector<int> row(i);
        for(int& x : row)
            cin >> x;
        tri.push_back(row);

        max_score.emplace_back(row);
    }

    for(int i = 0; i < r - 1; i++) {
        // either down left or right

        for(int j = 0; j <= i; j++) {
            int c = max_score[i][j];
            int& l = max_score[i + 1][j];
            int& r = max_score[i + 1][j + 1];
            l = max(l, tri[i + 1][j] + c);
            r = max(r, tri[i + 1][j + 1] + c);
        }
    }

    int most = 0;
    for(int x : max_score[r - 1]) {
        most = max(most, x);
    }

    cout << most << '\n';
}