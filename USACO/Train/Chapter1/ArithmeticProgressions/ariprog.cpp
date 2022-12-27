/*
ID: shadax31
LANG: C++
TASK: ariprog
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

#define N_BISQ 125001
bool bisq[N_BISQ];
vector<int> allbisq;
int n, m;

int main() {
    InitIO("ariprog");

    cin >> n >> m;
    
    fill_n(bisq, N_BISQ, false);
    for(int p = 0; p <= m; p++)
        for(int q = 0; q <= m; q++) {
            int x = p*p + q*q;
            allbisq.push_back(x);
            bisq[x] = true;
        }
    
    sort(allbisq.begin(), allbisq.end());

    int prev = -1;
    vector<int> bisquares;
    for(int x : allbisq) {
        if(x != prev) {
            bisquares.push_back(x);
            prev = x;
        } 
    }

    for(int x : bisquares) {
        //cout << x << '\n';
    }

    int biggest = 2 * m * m;

    //cout << bisquares.size() << '\n';
    //cout << bisquares.back() / (n-1) << '\n';

    bool found = false;

    for(int b = 1; b <= biggest / (n-1); b++) {
        for(int i = 0; i < bisquares.size(); i++) {
            int cur_offset = bisquares[i] % b;

            int next_num = bisquares[i];
            bool works = true;
            for(int j = 1; j < n; j++) {
                next_num += b;
                if(next_num > biggest || !bisq[next_num]) {
                    works = false;
                    break;
                } 
            }

            if(works) {
                found = true;
                cout << bisquares[i] << ' ' << b << '\n';
            }
        }
    }

    if(!found)
        cout << "NONE\n";
}   