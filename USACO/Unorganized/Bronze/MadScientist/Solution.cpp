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

int main() {
    InitIO("breedflip");

    int n;
    std::cin >> n;
    std::string Current, Target;
    Current.reserve(n); Target.reserve(n);
    std::cin >> Current >> Target;

    int Substrings = 0;
    for(int i = 0; i < n; i++) {
        int increment;
        for(increment = i; increment < n && Current[increment] != Target[increment]; increment++);
        if(increment != i) Substrings++;
        i = increment;
    }
    std::cout << Substrings << '\n';

    return 0;
}