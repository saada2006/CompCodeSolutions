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

int getWinIndex(int i) {
    i++;
    return (i % 3);
}

// each thing wins against the index after it
int main() {
    InitIO("hps");
    int n; 
    cin >> n;

    vector<int> moves[3];

    for(int i = 0; i < 3; i++) {
        moves[i].resize(n + 1);
        moves[i][0] = 0;
    }

    for(int i = 1; i <= n; i++) {
        moves[0][i] = moves[0][i - 1];
        moves[1][i] = moves[1][i - 1];
        moves[2][i] = moves[2][i - 1];

        char c;
        cin >> c;
        
        if(c == 'S') {
            moves[0][i]++;
        } else if(c == 'P') {
            moves[1][i]++;
        } else {
            moves[2][i]++;
        }
    }

    int maxwins = 0;
    for(int i = 1; i <= n; i++) {
        // for all combos of before and after
        for(int j = 0; j < 3; j++) {
            for(int k = 0; k < 3; k++) {
                int a = getWinIndex(j);
                int b = getWinIndex(k);

                int wins = moves[a][i - 1] + moves[b][n] - moves[b][i - 1];
                maxwins = max(maxwins, wins);
            }
        }
    }

    cout << maxwins << '\n';
}