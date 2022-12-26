/*
ID: shadax31
LANG: C++
TASK: transform
*/
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
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



using namespace std;

int n;

vector<string> rotate(vector<string> src) {
    vector<string> dst;
    dst.resize(n);

    for(auto& s : dst)
        s.resize(n);

    for(int i = 0; i < n; i++) 
        for(int j = 0; j < n; j++)
            dst[i][j] = src[n - 1 - j][i];
    
    return dst;
}

vector<string> reflect(vector<string> src) {
    vector<string> dst = src;
    for(auto& s : dst)
        reverse(s.begin(), s.end());
    return dst;
}

bool grids_equal(vector<string> src, vector<string> dst) {
    for(int i = 0; i < n; i++) 
        for(int j = 0; j < n; j++)
            if(dst[i][j] != src[i][j])
                return false;
    return true;
}

int get_rotate(vector<string> src, vector<string> dst) {
    for(int i = 1; i <= 3; i++) {
        src = rotate(src);
        if(grids_equal(src, dst))
            return i;
    }

    return 7;
}

int get_id(vector<string> src, vector<string> dst) {
    vector<string> copy_src = src;
    int rid = get_rotate(src, dst);

    if(rid == 7) {
        src = reflect(src);
        if(grids_equal(src, dst))
            rid = 4;
        else {
            rid = get_rotate(src, dst);
            if(rid != 7)
                rid = 5;
        }
    }

    if(rid == 7 && grids_equal(copy_src, dst))
        rid = 6;

    return rid;
}

void dump_grid(vector<string> src) {
    for(auto s: src)
        cout << s << '\n';
}

int main() {
    InitIO("transform");
    
    cin >> n;

    vector<string> src;
    src.resize(n);
    for(auto& s : src)
        cin >> s;

    vector<string> dst;
    dst.resize(n);
    for(auto& s : dst)
        cin >> s; 

    
    cout << get_id(src, dst) << '\n';
}