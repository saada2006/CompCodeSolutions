#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

void solve() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> Endpoints(2 * n);
    std::vector<std::pair<int, int>> Connections;
    Connections.reserve(n);
    for(int i = 0; i < 2 * n; i++) {
        Endpoints[i] = i;
    }

    for(int i = 0; i < k; i++) {
        std::pair<int, int> Chord;
        std::cin >> Chord.first >> Chord.second;
        Chord.first--; Chord.second--;
        if(Chord.first > Chord.second) {
            std::swap(Chord.first, Chord.second);
        }
        Endpoints.erase(std::lower_bound(Endpoints.begin(), Endpoints.end(), Chord.first ));
        Endpoints.erase(std::lower_bound(Endpoints.begin(), Endpoints.end(), Chord.second));
        Connections.push_back(Chord);
    }

    int d = n - k;

    for(int i = 0; i < d; i++) {
        int j = i + d;
        Connections.push_back(std::make_pair(Endpoints[i], Endpoints[j]));
    }

    std::sort(Connections.begin(), Connections.end());

    int NumIntersections = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(Connections[j].first < Connections[i].second && Connections[j].second > Connections[i].second) {
                NumIntersections++;
            }
        }
    }

    std::cout << NumIntersections << '\n';
}

int main() {
    int t;
    std::cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}