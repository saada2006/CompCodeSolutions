/*
ID: shadax31
LANG: C++
TASK: hamming
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

// tiebreaking objectives
// greedily choose smallest numbers
// pick a starting number
// go through numbers that fit the set and add or not

int hd(int a, int b) {
    int num = 0;

    for(int i = 0; i < 8; i++) {
        int p = (1 << i);
        bool oa = ((a & p) != 0);
        bool ob = ((b & p) != 0);

        if(oa != ob) {
            num++;
        }
    }

    return num;
}

bool search(int tot, int n, int d, vector<int>& sol) {
    if(sol.size() == n) {
        return true;
    }

    // find next num
    for(int i = sol.back() + 1; i < tot; i++) {
        bool good = true;

        for(int j = 0; j < sol.size(); j++) {
            if(hd(i, sol[j]) < d) {
                good = false;
                break;
            }
        }

        if(good) {
            sol.push_back(i);
            if(search(tot, n, d, sol)) {
                return true;
            }
            sol.pop_back();
        }
    }

    return false;
}

int main() {
    InitIO("hamming");

    int n, b, d;
    cin >> n >> b >> d;

    int tot = (1 << b);

    vector<int> sol;
    for(int i = 0; i < tot; i++) {
        sol.clear();

        sol.push_back(i);
        if(search(tot, n, d, sol)) {
            break;
        }
    }

    for(int i = 0; i < n; i++) {
        bool line = (((i + 1) % 10 == 0) || (i + 1 == n));
        cout << sol[i] << (line ? '\n' : ' ');
    }
}