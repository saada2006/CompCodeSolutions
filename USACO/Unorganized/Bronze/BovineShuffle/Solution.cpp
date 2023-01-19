#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

int main() {
    freopen("shuffle.in", "r", stdin);
    freopen("shuffle.out", "w", stdout);

    int n;
    std::cin >> n;

    std::vector<int> ShuffleTable(n), CowIDs(n), SwapMemory(n);

    for(int& x : ShuffleTable) {
        std::cin >> x;
        x--;
    }

    auto ShuffleTableCopy = ShuffleTable;
    // ShuffleTable: cow at x ptr -> y index
    // Goal: y -> x

    for(int i = 0; i < n; i++) {
        ShuffleTableCopy[ShuffleTable[i]] = i;
    }

    std::copy(ShuffleTableCopy.begin(), ShuffleTableCopy.end(), ShuffleTable.begin());

    for(int& x : CowIDs) {
        std::cin >> x;
    }

    for(int Shuffle = 0; Shuffle < 3; Shuffle++) {
        for(int Cow = 0; Cow < n; Cow++) {
            SwapMemory[ShuffleTable[Cow]] = CowIDs[Cow];
        }
        std::copy(SwapMemory.begin(), SwapMemory.end(), CowIDs.begin());
    }

    for(const int ID : CowIDs) {
        std::cout << ID << '\n';
    }

    return 0;
}