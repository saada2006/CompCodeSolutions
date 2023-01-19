#include <iostream>
#include <vector>
#include <algorithm>

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> Map(n + 1, 0);
    for(int i = 0; i < n; i++) {
        int j;
        std::cin >> j;
        Map[j]++;
    }

    int MaxTeams = std::numeric_limits<int>::min();

    for(int i = 1; i <= 2 * n; i++) {
        int L =  i      / 2;
        int R = (i + 1) / 2;

        int CurTeams = 0;
        while(L >= 0 && R <= n) {
            if(L == R) {
                CurTeams += Map[L] / 2;
            } else {
                CurTeams += std::min(Map[L], Map[R]);
            }
            L--;
            R++;
        }

        MaxTeams = std::max(MaxTeams, CurTeams);
    }

    std::cout << MaxTeams << '\n';
}

int main() {
    int t;
    std::cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}