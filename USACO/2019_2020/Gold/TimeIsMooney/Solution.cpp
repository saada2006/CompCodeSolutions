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

/*
Idea: at any city, which path, that ends at the first city, makes the most money?
Terminate the search if the accumulated cost falls below the city with the highest moeny amount (ie there's no way we can get a positive value)
*/

#include <vector>
#include <map>
#include <algorithm>
#include <stdint.h>

/*
A valid path is defined as one that ends at the first city (city = 0)
*/
int search(const std::vector<int>& rewards, std::map<int, std::vector<int>>& paths, int most, int c, int depth, int city, int accum) {
    if(most + accum < 0 || depth > 1000) {
        return 0;
    }

    int money;
    if(city == 0) {
        money = accum;
    } else {
        money = INT32_MIN;
    }

    int cost = c * (2 * depth + 1);
    for(const auto& reachable : paths[city]) {
        money = std::max(money, search(rewards, paths, most, c,  depth + 1, reachable, accum + rewards[reachable] - cost));
    }

    return money;
}

int main() {
    //#ifdef ONLINE_JUDGE
    InitIO("time");
    //#endif

    int n, m, c;

    std::cin >> n >> m >> c;

    int most = 0;

    std::vector<int> rewards(n);
    for(int& x : rewards) {
        std::cin >> x;
        most = std::max(most, x);
    }

    std::map<int, std::vector<int>> paths;
    for(int i = 0; i < m; i++) {
        int x, y;
        std::cin >> x >> y;
        x--;
        y--;
        paths[x].push_back(y);
    }

    int best = search(rewards, paths, most, c, 0, 0, 0);
    std::cout << best << '\n';
}