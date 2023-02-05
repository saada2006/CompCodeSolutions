#include <iostream>
#include <vector>

using namespace std;

#include <iostream>
#include <cstdio>
void InitIO(const char* FileName) {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    
    constexpr std::size_t BufferSize = 256;
    char StrBuf[BufferSize];

    StrBuf[0] = '\0';
    std::snprintf(StrBuf, BufferSize, "%s.in", FileName);
    std::freopen(StrBuf, "r", stdin);

    StrBuf[0] = '\0';
    std::snprintf(StrBuf, BufferSize, "%s.out", FileName);
    std::freopen(StrBuf, "w+", stdout);    
}

int main() {
    InitIO("bcount");

    int n, q;
    cin >> n >> q;

    vector<int> cows(n);
    for(int& x : cows) {
        cin >> x;
        x--;
    }

    vector<int> count[3];
    count[0].resize(n + 1);
    count[1].resize(n + 1);
    count[2].resize(n + 1);

    count[0][0] = 0;
    count[1][0] = 0;
    count[2][0] = 0;


    for(int i = 0; i < n; i++) {
        count[0][i + 1] = count[0][i];
        count[1][i + 1] = count[1][i];
        count[2][i + 1] = count[2][i];

        count[cows[i]][i + 1]++;
    }

    for(int i = 0; i < q; i++) {
        int a, b;

        cin >> a >> b;
        a--;


        cout << count[0][b] - count[0][a] << ' ' << count[1][b] - count[1][a] << ' ' << count[2][b] - count[2][a] << '\n';
    }
}