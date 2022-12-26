#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, m;
    std::cin >> n >> m;

    int RemainingNobles = n;
    std::vector<int> Friendships(n, 0);
    for(int i = 0; i < m; i++) {
        int a, b;
        std::cin >> a >> b;
        int ModifyIdx = std::min(a, b) - 1;
        if(Friendships[ModifyIdx] == 0) {
            RemainingNobles--;
        }
        Friendships[ModifyIdx]++;
    }

    int q;
    std::cin >> q;

    for(int i = 0; i < q; i++) {
        int qt;
        std::cin >> qt;

        if(qt == 1) {
            int a, b;
            std::cin >> a >> b;
            int ModifyIdx = std::min(a, b) - 1;
            if(Friendships[ModifyIdx] == 0) {
                RemainingNobles--;
            }
            Friendships[std::min(a, b) - 1]++;
        } else if(qt == 2) {
            int a, b;
            std::cin >> a >> b;
            int ModifyIdx = std::min(a, b) - 1;
            Friendships[std::min(a, b) - 1]--;
            if(Friendships[ModifyIdx] == 0) {
                RemainingNobles++;
            }
        } else {
            std::cout << RemainingNobles << '\n';
        }
    }
}