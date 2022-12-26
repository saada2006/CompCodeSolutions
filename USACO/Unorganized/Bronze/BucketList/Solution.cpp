#include <fstream>
#include <utility>
#include <algorithm>
#include <set>

int main() {
    std::ifstream Input("blist.in");
    std::ofstream Output("blist.out");

    int n;
    Input >> n;

    std::set<std::pair<int, int>> Events;
    for(int i = 0; i < n; i++) {
        int s, t, b;
        Input >> s >> t >> b;
        Events.insert(std::make_pair(s,  b));
        Events.insert(std::make_pair(t, -b));
    }

    int MaxBuckets = 0;
    int NextBuckets = 0;
    for(const auto& Event : Events) {
        NextBuckets += Event.second;
        MaxBuckets = std::max(MaxBuckets, NextBuckets);
    }

    Output << MaxBuckets;

    return 0;
}