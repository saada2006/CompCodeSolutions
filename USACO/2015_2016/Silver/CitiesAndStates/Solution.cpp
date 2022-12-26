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

#include <map>
#include <string>
#include <cstdint>

int main() {
    InitIO("citystate");

    int n;
    std::cin >> n;

    std::map<std::string, int64_t> codes;
    for(int i = 0; i < n; i++) {
        std::string city, state;
        std::cin >> city >> state;

        city.resize(2);

        // The problem description says that special pairs MUST come from different states, and the only way this can happen is if the state code is the same as the city code
        if(city == state) {
            continue;
        }

        codes[city + state]++;
    }

    int64_t sum = 0;
    for(auto& a : codes) {
        std::string c = a.first.substr(0, 2);
        std::string s = a.first.substr(2, 4);
        std::string search = s + c;

        auto& b = codes[search];
        sum += a.second * b;
        b = 0;
    }

    std::cout << sum << '\n';
}