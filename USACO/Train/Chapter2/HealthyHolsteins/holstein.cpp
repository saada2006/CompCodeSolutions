/*
ID: shadax31
LANG: C++
TASK: holstein
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
#include <queue>
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
    InitIO("holstein");

    int v;
    cin >> v;

    vector<int> needs(v);
    for(int& x : needs) 
        cin >> x;

    int g;
    cin >> g;
    vector<vector<int>> scoops(g);
    for(auto& s : scoops) {
        s.resize(v);
        for(int& x : s) 
            cin >> x;
    }   

    vector<int> ans;
    vector<int> diet(v);
    for(int i = 0; i < (1 << g); i++) {
        vector<int> record;

        fill(diet.begin(), diet.end(), 0);
        for(int j = 0; j < g; j++) {
            if((i & (1 << j)) != 0) {
                record.push_back(j);
                for(int k = 0; k < v; k++) {
                    diet[k] += scoops[j][k];
                }
            } 
        }

        bool good = true;
        for(int j = 0; j < v; j++) {
            if(diet[j] < needs[j]) {
                good = false;
                break;
            }
        }

        if(good && (record.size() < ans.size() || ans.empty())) {
            ans = record;
        }
    }

    cout << ans.size() << ' '; 
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] + 1 << (i + 1 == ans.size() ? '\n' : ' ');
    }
}