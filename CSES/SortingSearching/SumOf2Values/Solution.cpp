#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, x;
    std::cin >> n >> x;
    std::vector<int> Data(n);
    for(int& x : Data) {
        std::cin >> x;
    }
    auto Sorted = Data;
    std::sort(Sorted.begin(), Sorted.end());
    for(auto Iter = Sorted.begin(); Iter != Sorted.end(); Iter++) {
        int A = *Iter;
        int B = x - A;
        auto Pair = std::lower_bound(Sorted.begin(), Sorted.end(), B);
        if(Pair == Sorted.end() || *Pair != B) {
            continue;
        }
        if(Pair == Iter) {
            Pair++;
            if(*Pair != B) {
                continue;
            }
        }

        auto Pos0 = std::find(Data.begin(), Data.end(), *Iter);
        auto Pos1 = std::find(Pos0 + 1, Data.end(), *Pair);

        if(Pos0 == Data.end() || Pos1 == Data.end()) {
            Pos0 = std::find(Data.begin(), Data.end(), *Pair);
            Pos1 = std::find(Pos0 + 1, Data.end(), *Iter);
        }

        std::cout << std::distance(Data.begin(), Pos0) + 1 << ' '
                  << std::distance(Data.begin(), Pos1) + 1 << '\n';
        return 0;
    }
    std::cout << "IMPOSSIBLE\n";
    return 0;
}