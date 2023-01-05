/*
ID: shadax31
LANG: C++
TASK: castle
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

struct connections {
    bool vals[4];

    bool& operator[](int i) {
        return vals[i];
    }
};

int main() {
    InitIO("castle");

    int m, n;
    cin >> m >> n;

    vector<vector<connections>> castle;
    castle.resize(n);
    for(auto& v : castle) {
        v.resize(m);
        for(auto& x : v) {
            int w;
            cin >> w;
            //cout << w << '\t';

            x[0] = ((w & 1) == 0);
            x[1] = ((w & 2) == 0);
            x[2] = ((w & 4) == 0);
            x[3] = ((w & 8) == 0);
        }
        //cout << '\n'; // don't you really hate it when the usaco grader doesn't give you first time congrats cuz of some stupid formating error?
    }

    vector<vector<int>> room_id;
    vector<int> room_size;
    int next_room = 0;

    room_id.resize(n);
    for(auto& v : room_id) {
        v.resize(m);
        fill(v.begin(), v.end(), -1);
    }    

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) {
            if(room_id[i][j] != -1) continue;


            // else do search
            room_size.push_back(0);
            int& cursize = room_size.back();
            cursize = 0;
            int curroom = next_room;
            next_room++;

            queue<pair<int, int>> nextnode;
            nextnode.emplace(i, j);
            room_id[i][j] = curroom;

            while(!nextnode.empty()) {
                auto curnode = nextnode.front();
                nextnode.pop();
                cursize++;

                int a = curnode.first, b = curnode.second;
                
                //cout << a << ' ' << b << '\n';

                if(castle[a][b][0] && room_id[a][b - 1] == -1) {
                    nextnode.emplace(a, b - 1);
                    room_id[a][b - 1] = curroom;
                }

                if(castle[a][b][1] && room_id[a - 1][b] == -1) {
                    nextnode.emplace(a - 1, b);
                    room_id[a - 1][b] = curroom;
                }

                if(castle[a][b][2] && room_id[a][b + 1] == -1) {
                    nextnode.emplace(a, b + 1);
                    room_id[a][b + 1] = curroom;
                }

                if(castle[a][b][3]&& room_id[a + 1][b] == -1) {
                    nextnode.emplace(a + 1, b);
                    room_id[a + 1][b] = curroom;
                }
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            //cout << room_id[i][j] << '\t';
        }
        //cout << '\n';
    }

    int max_size = 0;
    for(int x : room_size)
        if(x > max_size)
            max_size = x;

    cout << room_size.size() << '\n';
    cout << max_size << '\n';


    //return 0 ;
    // now, consider each wall:
    // what would be the new volume if we tore down this wall?

    int best_vol = 0;
    int best_a = 0, best_b = 0;
    char best_c = 'E';

    for(int j = 0; j < m; j++) {
        for(int i = n - 1; i >= 0; i--) {
            // test north first for tiebreaker
            if(i != 0 && room_id[i][j] != room_id[i - 1][j]) {
                int new_vol = room_size[room_id[i][j]] + room_size[room_id[i - 1][j]];
                if(new_vol > best_vol) {
                    best_vol = new_vol;
                    best_a = i;
                    best_b = j;
                    best_c = 'N';
                }
            }

            // test east
            if(j + 1 != m && room_id[i][j] != room_id[i][j + 1]) {
                int new_vol = room_size[room_id[i][j]] + room_size[room_id[i][j + 1]];
                if(new_vol > best_vol) {
                    best_vol = new_vol;
                    best_a = i;
                    best_b = j;
                    best_c = 'E';
                }
            }

        }
    }


    cout << best_vol << '\n';
    cout << best_a + 1 << ' ' << best_b + 1 << ' ' << best_c << '\n';
}