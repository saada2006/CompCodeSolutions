#include <iostream>
#include <string>

void solve() {
    std::string Source, Record;
    std::cin >> Source >> Record;

    size_t Position = 0;
    while(true) {
        Position = Source.find(Record.front(), Position);
        if(Position == std::string::npos) {
            std::cout << "NO\n";
            return;
        }

        int NextIdx = 0;
        int Remainder = Record.size() - 1;

        for(int Chip = Position++; Chip < Source.size(); Chip++, NextIdx++, Remainder--) {
            if(Source[Chip] != Record[NextIdx]) {
                break;
            }

            if(Remainder == 0) {
                std::cout << "YES\n";
                return;
            }

            if(Chip < Remainder) {
                continue;
            }

            int NextIdx2 = NextIdx + 1;
            for(int Chip2 = Chip - 1; NextIdx2 < Record.size(); NextIdx2++, Chip2--) {
                if(Source[Chip2] != Record[NextIdx2]) {
                    break;
                }
            }

            if(NextIdx2 == Record.size()) {
                std::cout << "YES\n";
                return;
            }
        }
    }
}

int main() {
    int t;
    std::cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}