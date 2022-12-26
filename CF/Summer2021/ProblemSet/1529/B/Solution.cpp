#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int FindSolution(std::vector<int> Data) {
    std::sort(Data.begin(), Data.end());

    int MinDiff = 2147483647;
    int NumElements = 1;
    int PreviousElem = Data.front();
    for(auto Iter = Data.begin() + 1; Iter != Data.end(); Iter++) {
        // Add element if the (new) max diff doesn't exceed the diff
        int CurrentElem = *Iter;
        MinDiff = std::min(MinDiff, CurrentElem - PreviousElem);
        if(CurrentElem <= MinDiff) { // Since Data is sorted CurrentElem is MAX
            PreviousElem = CurrentElem;
            NumElements++;
        } else {
            break;
        }
    }

    return NumElements;
}

int main() {
    int t;
    std::cin >> t;

    for(int i = 0; i < t; i++) {
        int n;
        std::cin >> n;

        std::vector<int> Data(n);
        for(int& x : Data) {
            std::cin >> x;
        }

        std::cout << FindSolution(Data) << '\n';
    }
}