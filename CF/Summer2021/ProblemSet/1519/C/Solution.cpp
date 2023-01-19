#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

struct University {
    int Number;
    std::vector<std::int64_t> Prefix;

    bool operator<(const University& Other) const {
        return (Prefix.size() < Other.Prefix.size());
    }
};

void solve() {
    int n;
    std::cin >> n;

    std::vector<University> PlayerSenders(n);
    std::vector<int> Players(n);

    for(int& Uni : Players) {
        std::cin >> Uni;
        Uni--;
    }

    for(const int Uni : Players) {
        int Skill;
        std::cin >> Skill;
        University* Insert = &PlayerSenders[Uni];

        if(Insert->Prefix.size() + 1 >= Insert->Prefix.capacity()) {
            Insert->Prefix.reserve(Insert->Prefix.size() * 2 + 2);
        }

        Insert->Prefix.push_back(Skill);
    }

    std::sort(PlayerSenders.rbegin(), PlayerSenders.rend());
    for(University& Uni : PlayerSenders) {
        std::sort(Uni.Prefix.rbegin(), Uni.Prefix.rend());
        std::partial_sum(Uni.Prefix.begin(), Uni.Prefix.end(), Uni.Prefix.begin());
    }

    for(int k = 1; k <= n;  k++) {
        std::int64_t RegionSkill = 0;
        for(const University& Uni : PlayerSenders) {
            if(Uni.Prefix.size() < k) {
                break;
            } else {
                int Idx = k * (Uni.Prefix.size() / k);
                RegionSkill += Uni.Prefix[Idx - 1];
            }
        }

        std::cout << RegionSkill << ' ';
    }

    std::cout << '\n';
}

int main() {
    int t;
    std::cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}