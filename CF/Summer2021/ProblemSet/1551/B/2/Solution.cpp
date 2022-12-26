#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>

// This problem really hurt my brain
// Is Div 3 really the same as USACO Bronze?
// Because if it is I'm never going to get good at comp programming
// I had to look at the solution ffs

void solve() {
    int n, k;
    std::cin >> n >> k;

    std::map<int, std::vector<int>> Sequence;
    for(int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        std::vector<int>* Indicies = &Sequence[x];
        if(Indicies->size() < k) {
            Indicies->push_back(i);
        }
    }

    int MaxColoredParts = 0;
    for(const auto& VecSize : Sequence) {
        MaxColoredParts += VecSize.second.size();
    }
    MaxColoredParts -= MaxColoredParts % k; // Round down
    
    int CurrentColor = 0;
    std::vector<int> ColoredIntegers(n, 0);

    bool MoreColorsLeft = true;
    for(auto& Element : Sequence) {
        for(int Idx : Element.second) {
            CurrentColor++;
            ColoredIntegers[Idx] = CurrentColor;
            CurrentColor %= k;
            MaxColoredParts--;
            if(MaxColoredParts == 0) {
                MoreColorsLeft = false;
                break;
            }
        }
        if(!MoreColorsLeft) {
            break;
        }
    }

    for(const int Clr : ColoredIntegers) {
        std::cout << Clr << ' ';
    }

    std::cout << '\n';
}

int main() {
    int t;
    std::cin >> t;

    for(int i = 0; i < t; i++) {
        solve();
    }

    return 0;
}