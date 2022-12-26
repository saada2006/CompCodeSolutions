/*
ID: shadax31
LANG: C++
TASK: wormhole
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

int n;
vector<int> pairings;
vector<pair<int, int>> locs;

bool test_pairings() {
    // start at each loc
    for(int i = 0; i < n; i++) {
        int pos = i;

        set<pair<int, int>> visited;
        vector<pair<int, int>> ordered_visted;
        while(true) {
            int yi = locs[pos].first;
            int npos = pos + 1;
            int yf = locs[npos].first;

            if(yi != yf) // cont to inf
                break;
            else {
                // visited endpoint before?
                ordered_visted.push_back(locs[pos]);
                pos = npos;

                if(visited.count(locs[pos]) == 1) {
                    ordered_visted.push_back(locs[pos]);
                    //for(auto p : ordered_visted)
                        //cout << p.second << '\t' << p.first << '\n';
                    //cout << "=======\n";
                    return true;
                }
                else {
                    visited.insert(locs[pos]);
                    ordered_visted.push_back(locs[pos]);

                    int x;
                    for(x = 0; x < n; x += 2) 
                        if(pairings[x] == pos || pairings[x + 1] == pos)
                            break;
                    
                    if(pairings[x] == pos)
                        x++;
                    
                    pos = pairings[x];
                }
                
            }
        }
    }
    return false;
}

// actual challenge is finding lazy way to pair 12 numbers

int sols = 0;
bool paired[12];

void recurse() {
    if(pairings.size() == n) {
        if(test_pairings()) {
            sols++;
        }
    } else {
        int nup = 0;
        while(paired[nup]) nup++;
        /*if(nup >= n) {
            cout << pairings.size() << '\n';
            cout << "nup " << nup << '\n';
            for(int i = 0; i < n; i++) {
                cout << (int)paired[i];
            }
            cout << '\n';
            //return;
        }*/
        paired[nup] = true;
        pairings.push_back(nup);
        for(int i = 0; i < n; i++) {
            if(!paired[i]) {
                paired[i] = true;
                pairings.push_back(i);
                recurse();
                paired[i] = false;
                pairings.pop_back();
            }
        }
        paired[nup] = false;
        pairings.pop_back();
    }
}

int main() {
    InitIO("wormhole");

    cin >> n;
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        locs.emplace_back(y, x);
    }

    sort(locs.begin(), locs.end());

    fill_n(paired, n, false);
    recurse();

    cout << sols << '\n';
}