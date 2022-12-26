#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cstdio>

struct TrafficEvent {
    bool Change;  // Ramp or not?
    int Min, Max; // Range of values (negative for off ramps)
};

int main() {
    freopen("traffic.in", "r", stdin);
    freopen("traffic.out", "w", stdout);

    int n;
    std::cin >> n;
    std::vector<TrafficEvent> Events(n);
    for(auto& Event : Events) {
        std::string s;
        std::cin >> s;
        int a, b;
        std::cin >> a >> b;
        Event.Min = a;
        Event.Max = b;
        if(s.compare("on") == 0) {
            Event.Change = true;
        } else if(s.compare("off") == 0) {
            Event.Change = true;
            Event.Min *= -1;
            Event.Max *= -1;
            std::swap(Event.Min, Event.Max);
        } else {
            Event.Change = false;
        }
    }

    std::pair<int, int> Start = std::make_pair(-1000000, 10000000), Final = std::make_pair(-1000000, 10000000); 

    for(auto EventIter = Events.rbegin(); EventIter != Events.rend(); EventIter++) {
        if(EventIter->Change) {
            Start.first -= EventIter->Max;
            Start.second -= EventIter->Min;

            Start.first = std::max(Start.first, 0);
            Start.second = std::max(Start.second, 0);
        } else {
            Start.first = std::max(Start.first, EventIter->Min);
            Start.second = std::min(Start.second, EventIter->Max);
        }
    }

    for(auto EventIter = Events.begin(); EventIter != Events.end(); EventIter++) {
        if(EventIter->Change) {
            Final.first += EventIter->Min;
            Final.second += EventIter->Max;

            Final.first = std::max(Final.first, 0);
            Final.second = std::max(Final.second, 0);
        } else {
            Final.first = std::max(Final.first, EventIter->Min);
            Final.second = std::min(Final.second, EventIter->Max);
        }
    }    

    std::cout << Start.first << ' ' << Start.second << '\n';
    std::cout << Final.first << ' ' << Final.second << '\n';

    return 0;
}

/*
  std::pair<int, int> Start = std::make_pair(-1000000, 10000000), Final = std::make_pair(-1000000, 10000000); 
    std::pair<int, int> AccumRangeDiff = std::make_pair(0, 0);

    for(auto EventIter = Events.begin(); EventIter != Events.end(); EventIter++) {
        if(EventIter->Change) {
            AccumRangeDiff.first -= EventIter->Max;
            AccumRangeDiff.second -= EventIter->Min;
        } else {
            Start.first = std::max(Start.first, EventIter->Min + AccumRangeDiff.first);
            Start.second = std::min(Start.second, EventIter->Max + AccumRangeDiff.second);     
            EnsurePositive(Start, AccumRangeDiff);    
        }
    }

    AccumRangeDiff.first = AccumRangeDiff.second = 0;
    for(auto EventIter = Events.rbegin(); EventIter != Events.rend(); EventIter++) {
        if(EventIter->Change) {
            AccumRangeDiff.first += EventIter->Max;
            AccumRangeDiff.second += EventIter->Min;
        } else {
            Final.first = std::max(Final.first, EventIter->Min + AccumRangeDiff.first);
            Final.second = std::min(Final.second, EventIter->Max + AccumRangeDiff.second);   
            EnsurePositive(Final, AccumRangeDiff);          
        }
    }   
*/