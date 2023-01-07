/*
ID: shadax31
LANG: C++
TASK: sort3
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

// 2 3 1

// 1 3 2 -> 1 2 3

// 2 1 3 -> 1 2 3

int main() {
    InitIO("sort3");

    int n;
    cin >> n;
    vector<int> v(n);

    for(int& x : v) {
        cin >> x;
        x--;
    }

    auto s = v;
    sort(s.begin(), s.end());

    int c = 0;
    for(int i = 0; i < n; i++) {
        if(v[i] != s[i]) {   
            // find next, kill two birds with one store
            bool found = false;
            for(int j = i + 1; j < n; j++) {
                if(v[j] == s[i] && v[j] != s[j] && s[j] == v[i]) {
                    swap(v[i], v[j]);
                    found = true;
                    c++;
                    break;
                }
            }

            if(!found) {
                // awww man, we can only sort one
                for(int j = i + 1; j < n; j++) {
                    if(v[j] == s[i] && v[j] != s[j]) {
                        swap(v[i], v[j]);
                        found = true;
                        c++;
                        break;
                    }
                }                
            }
        }
    }

    cout << c << '\n';

}

/*

        1 
        2 
        3 
        2 
        3 
        1 

1 1 2 2 3 3
1 2 3 2 3 1
  2 3 1


1 2 3 2 3 1
1 2 1 2 3 3


1 2 3 2 3 1
1 1 3 2 3 2
*/