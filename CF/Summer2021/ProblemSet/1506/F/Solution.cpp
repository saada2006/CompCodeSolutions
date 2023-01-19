#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

void solve() {
    int n;
    std::cin >> n;

    std::vector<std::pair<int, int>> Nodes(n);
    for(auto& Nd : Nodes) {
        std::cin >> Nd.first;
    }
    for(auto& Nd : Nodes) {
        std::cin >> Nd.second;
    }
    std::sort(Nodes.begin(), Nodes.end());

    int Cost = 0;
    std::pair<int, int> Curr = std::make_pair(1, 1);
    for(const auto Next : Nodes) {

        int Sum = Curr.first + Curr.second;
        auto Diff = std::make_pair(
            Next.first - Curr.first,
            Next.second - Curr.second
        );

        if(Sum % 2 == 0 && Diff.first == Diff.second) {
            Cost += Diff.first;
        } else {
            if(Sum % 2 == 0) {
                Curr.first++;
            }
            Curr.first += Diff.second;
            Cost += (Next.first - Curr.first + 1) / 2;
        }
        Curr = Next;
    }

    std::cout << Cost << '\n';
}

int main() {
    int t;
    std::cin >> t;

    while(t--)
        solve();
    
    return 0;
}