#include <cstdio>
#include <iostream>
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

#include <vector>
using namespace std;

int main() {
    InitIO("div7");
    int n;
    cin >> n;

    int prev = 0;
    vector<int> prefixr(n);
    for(int& x : prefixr) {
        cin >> x;
        x += prev;
        x %= 7;
        prev = x;
    }

    vector<int> smallest_loc[7];
    for(int i = 0; i < 7; i++) {
        smallest_loc[i].resize(n);

        int loc = -1;
        for(int j = 0; j < n; j++) {
            if(loc == -1 && prefixr[j] == i) {
                loc = j;
            }
            smallest_loc[i][j] = loc;
        }
    }

    int maxlen = 0;
    for(int i = 0; i < n; i++) {
        if(prefixr[i] == 0) {
            maxlen = i;
        } else if(i != 0) {
            // find an index
            int loc = smallest_loc[prefixr[i]][i - 1];
            if(loc != -1) {
                int len = i - loc;
                maxlen = max(maxlen, len);
                //cout << prefixr[i] << ' ' << i << ' ' << loc << '\n';
            }
        }
    }

    cout << maxlen << '\n';

}