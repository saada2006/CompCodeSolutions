// Copy paste for fast USACO file I/O redirection
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
#include <unordered_set>
#include <algorithm>

std::unordered_set<std::string> Paths;
char Field[18][18];
std::string PathBuilder;

/*
First check if char mirrors palindrome
Check if we have reached (n - 1, n - 1) so we can push back string
If yes push back and search(x + 1, y) and search(x, y + 1)
*/

int n;
int HalfLen;
int MaxIdx;


void Search(int depth, int x, int y) {
    char Current = Field[y][x];

    if(depth > HalfLen) {
        int Remaining = MaxIdx - depth;
        if(Current == PathBuilder[Remaining]) {
            PathBuilder.push_back(Current);
        } else {
            return;
        }
    } else {
        PathBuilder.push_back(Current);
    }

    if(x == n - 1 && y == n - 1) {
        Paths.insert(PathBuilder);
        PathBuilder.pop_back();
        return;
    }

    int NextDepth = depth + 1;
    if(x < n - 1) {
        Search(NextDepth, x + 1, y);
    }

    if(y < n - 1) {
        Search(NextDepth, x, y + 1);
    }

    PathBuilder.pop_back();
}

int main() {
    InitIO("palpath");

    std::cin >> n;
    HalfLen = n - 1;
    MaxIdx = 2 * n - 2;

    for(int i = 0; i < 18; i++) {
        std::string s;
        std::cin >> s;
        for(int j = 0; j < 18; j++) {
            Field[i][j] = s[j];
        }
    }

    if(Field[0][0] != Field[HalfLen][HalfLen]) {
        std::cout << "0\n";
        return 0;
    }

    PathBuilder.reserve(2 * n - 1);
    Search(0, 0, 0);
    std::cout << Paths.size() << '\n';

    return 0;
}