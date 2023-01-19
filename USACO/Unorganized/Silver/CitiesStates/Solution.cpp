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

#include <set>

struct City {
    char Name[2];
    char State[2];

    bool operator<(const City& Other) const {
        if(Name[0] == Other.Name[0]) {
            return Name[1] < Other.Name[1];
        } else {
            return Name[0] < Other.Name[0];
        }
    }
};

/*
For each city, we find the lower bound of cities with the same first two state letters as it's first 2 city letters, then iterate and avoid ones from same state
*/

int main() {
    InitIO("citystate");

    int n;
    std::cin >> n;

    std::multiset<City> Map;
    for(int i = 0; i < n; i++) {
        std::string c, s;
        std::cin >> c >> s;

        City CurrentCity;
        CurrentCity.Name[0] = c[0];
        CurrentCity.Name[1] = c[1];

        CurrentCity.State[0] = s[0];
        CurrentCity.State[1] = s[1];
        
        // Such cities would only match with their state anyway
        if(CurrentCity.Name[0] != CurrentCity.State[0] || CurrentCity.Name[1] != CurrentCity.State[1]) {
            Map.insert(CurrentCity);
        }
    }

    int NumPairs = 0;
    for(auto Iter = Map.begin(); Iter != Map.end(); Iter++) {
        // Find cities with same state names
        City Copy = *Iter;
        std::swap(Copy.State[0], Copy.Name[0]);
        std::swap(Copy.State[1], Copy.Name[1]);
        auto Find = Map.lower_bound(Copy);
        while(true) {
            if(Find != Map.end() && Copy.Name[0] == Find->Name[0] && Copy.Name[1] == Find->Name[1] && Copy.State[0] == Find->State[0] && Copy.State[1] == Find->State[1]) {
                NumPairs++;
                Find++;
            } else {
                break;
            }
        }
    }

    // We count all pairs twice so we div by 2
    NumPairs /= 2;
    std::cout << NumPairs << '\n';

    return 0;
}