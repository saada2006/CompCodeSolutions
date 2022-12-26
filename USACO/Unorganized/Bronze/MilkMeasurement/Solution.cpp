#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

struct MilkChange {
    int Day;
    char Cow;
    int Difference;

    bool operator<(const MilkChange& Other) {
        return (Day < Other.Day);
    }
};

struct CowMilk {
    char Name;
    int Production;
    CowMilk(void) : Production(0) {} // Intial doesn't actually matter  

    bool operator<(const CowMilk& Other) {
        if(Production == Other.Production) {
            return Name > Other.Name;
        }
        return (Production < Other.Production);
    }    
};

int main() {
    freopen("measurement.in", "r", stdin);
    freopen("measurement.out", "w", stdout);

    int NumChanges;
    std::cin >> NumChanges;

    std::vector<MilkChange> EventLog(NumChanges);
    for(auto& Change : EventLog) {
        std::cin >> Change.Day;
        std::string S;
        std::cin >> S;
        Change.Cow = S.front();
        S.clear();
        std::cin >> S;
        Change.Difference = (S.front() == '+' ? 1 : -1) * std::stoi(S.substr(1));
    }

    std::sort(EventLog.begin(), EventLog.end());

    CowMilk CowStats[3]; 
    CowStats[0].Name = 'B';
    CowStats[1].Name = 'E';
    CowStats[2].Name = 'M';

    char Winners[3] {'B', 'E', 'M'};
    int Answer = 0;

    for(int LogIndex = 0; LogIndex < EventLog.size(); LogIndex++) {
        auto Change = EventLog[LogIndex];

        if(Change.Cow == 'B') {
            CowStats[0].Production += Change.Difference;
        } else if(Change.Cow == 'E') {
            CowStats[1].Production += Change.Difference;
        } else {
            CowStats[2].Production += Change.Difference;
        }

        if(LogIndex + 1 == EventLog.size() || Change.Day != EventLog[LogIndex + 1].Day) {
            CowMilk SortedStats[3];
            std::copy_n(CowStats, 3, SortedStats);
            std::sort(SortedStats, SortedStats + 3);
            std::reverse(SortedStats, SortedStats + 3);

            int BestScore = SortedStats[0].Production;
            char NewWinners[3] {0, 0, 0};
            for(int Index = 0; Index < 3; Index++) {
                if(SortedStats[Index].Production == BestScore) {
                    NewWinners[Index] = SortedStats[Index].Name;
                }
            }

            for(int Index = 0; Index < 3; Index++) {
                if(NewWinners[Index] != Winners[Index]) {
                    Answer++;
                    break;
                }
            }

            std::copy_n(NewWinners, 3, Winners);
        }

        //std::cout << Winners[0] << ' ' << Winners[1] << ' ' << Winners[2] << '\n';

    }

    std::cout << Answer << '\n';
    return 0;
}

/*
int PreviousDay = 1;
    for(const auto& Change : EventLog) {
        // If Change.Day is different from PreviousDay update winners and check for change and then update PreviousDay
        if(Change.Day != PreviousDay) {
            CowMilk SortedStats[3];
            std::copy_n(CowStats, 3, SortedStats);
            std::sort(SortedStats, SortedStats + 3);

            int BestScore = SortedStats[0].Production;
            char NewWinners[3] {0, 0, 0};
            for(int Index = 0; Index < 3; Index++) {
                if(SortedStats[Index].Production == BestScore) {
                    NewWinners[Index] = SortedStats[Index].Name;
                }
            }

            for(int Index = 0; Index < 3; Index++) {
                if(NewWinners[Index] != Winners[Index]) {
                    Answer++;
                    break;
                }
            }

            std::copy_n(NewWinners, 3, Winners);

            PreviousDay = Change.Day;
        }
        // Then update the cow that Change modifies

        if(Change.Cow == 'B') {
            CowStats[0].Production += Change.Difference;
        } else if(Change.Cow == 'E') {
            CowStats[1].Production += Change.Difference;
        } else {
            CowStats[2].Production += Change.Difference;
        }

        std::cout << Winners[0] << ' ' << Winners[1] << ' ' << Winners[2] << '\n';
    }
*/