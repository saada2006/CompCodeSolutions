#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

int main() {
    freopen("speeding.in", "r", stdin);
    freopen("speeding.out", "w", stdout);

    int n, m;
    std::cin >> n >> m;
    std::vector<std::pair<int, int>> Road(n), Speeds(m);
    
    for(auto& x : Road) {
        std::cin >> x.first >> x.second;
    }

    for(auto& x : Speeds) {
        std::cin >> x.first >> x.second;
    }

    // For each segment
    auto SpeedIter = Speeds.begin();
    int HighestOverspeed = 0;
    int TraveledMiles = 0, CounterMiles = 0;
    for(const auto& Segment : Road) {        
        TraveledMiles += Segment.first;
        // Go onto the next part of the journey until the segment has been traveled
        while(CounterMiles < TraveledMiles) {
            CounterMiles += SpeedIter->first;
            HighestOverspeed = std::max(HighestOverspeed, SpeedIter->second - Segment.second);
            
            if(CounterMiles > TraveledMiles) {
                int Difference = CounterMiles - TraveledMiles;
                SpeedIter->first = Difference;
                CounterMiles = TraveledMiles;
            } else {
                SpeedIter++;
            }
        }
    }

    std::cout << HighestOverspeed;

    return 0;
}