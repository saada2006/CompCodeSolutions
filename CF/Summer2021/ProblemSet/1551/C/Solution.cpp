#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

struct Freq {
    int Map[5];
    Freq(void) {
        std::fill_n(Map, 5, 0);
    }
    void Insert(char c) {
        Map[c - 'a']++;
    }
    Freq ConstructRelFreq(void) {
        Freq RelFreq;

        RelFreq.Map[0] =  Map[0] - Map[1] - Map[2] - Map[3] - Map[4];
        RelFreq.Map[1] = -Map[0] + Map[1] - Map[2] - Map[3] - Map[4];
        RelFreq.Map[2] = -Map[0] - Map[1] + Map[2] - Map[3] - Map[4];
        RelFreq.Map[3] = -Map[0] - Map[1] - Map[2] + Map[3] - Map[4];
        RelFreq.Map[4] = -Map[0] - Map[1] - Map[2] - Map[3] + Map[4];

        return RelFreq;
    }
};

void solve(void) {
    int n;
    std::cin >> n;

    std::vector<Freq> Table(n);
    for(Freq& RelFreq : Table) {
        Freq CntFreq;
        std::string s;
        std::cin >> s;
        for(const char c : s) {
            CntFreq.Insert(c);
        }
        RelFreq = CntFreq.ConstructRelFreq();
    }

    int MaxInterestingWords = 0;

    for(int i = 0; i < 5; i++) {
        std::sort(Table.rbegin(), Table.rend(),
            [i](const Freq& Arg0, const Freq& Arg1) -> bool {
                return Arg0.Map[i] < Arg1.Map[i];
            }
        );

        int Difference = 0;
        for(int j = 0; j < n; j++) {
            Difference += Table[j].Map[i];
            if(Difference <= 0) {
                break;
            }
            MaxInterestingWords = std::max(MaxInterestingWords, j + 1);
        }
    }

    std::cout << MaxInterestingWords << '\n';
}

int main() {
    int t;
    std::cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}