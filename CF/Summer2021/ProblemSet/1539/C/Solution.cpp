#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdint>

int main() {
    std::int64_t n, k, x;
    std::cin >> n >> k >> x;

    std::vector<std::int64_t> Students(n);
    for(auto& s : Students) {
        std::cin >> s;
    }
    std::sort(Students.begin(), Students.end());

    std::vector<std::int64_t> GroupBarriers;
    for(auto Iter = Students.begin(); Iter != Students.end() - 1; Iter++) {
        std::int64_t Diff = *(Iter + 1) - *Iter;
        if(Diff > x) {
            GroupBarriers.push_back(Diff);
        }
    }
    std::sort(GroupBarriers.begin(), GroupBarriers.end());

    std::int64_t NumGroups = GroupBarriers.size() + 1;
    for(auto Diff : GroupBarriers) {
        std::int64_t NumStudentsRequired = (Diff - 1) / x;
        std::int64_t NumStudentsRemaining = k - NumStudentsRequired;
        
        if(NumStudentsRemaining >= 0) {
            k = NumStudentsRemaining;
            NumGroups--;
        } else {
            break;
        }
    }

    std::cout << NumGroups;
}