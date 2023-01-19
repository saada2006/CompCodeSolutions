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
    std::freopen(StrBuf, "w", stdout);    
}

#include <vector>
#include <string>

/*
First of all, if bottom left rectangle is tipping, UNTIP EVERYTHING

*/

void Flip(std::vector<std::vector<bool>>& Field, int x, int y) {
    for(int i = 0; i <= y; i++)  {
        for(int j = 0; j <= x; j++) {
            Field[i][j] = !Field[i][j];
        }
    }
}

int main() {
    InitIO("cowtip");

    int n;
    std::cin >> n;
    int nm1 = n - 1;
    std::vector<std::vector<bool>> Field(n);
    for(auto& Vec : Field) {
        Vec.resize(n);
        std::string s; std::cin >> s;
        for(int i = 0; i < n; i++) {
            Vec[i] = (s[i] == '1');
        }
    }

    int NumFlips = 0;
    for(int i = nm1; i >= 0; i--) {
        for(int j = nm1; j >= 0; j--) {
            if(Field[i][j]) {
                Flip(Field, j, i);
                NumFlips++;
            }
        }
    }

    std::cout << NumFlips << '\n';

    return 0;
}