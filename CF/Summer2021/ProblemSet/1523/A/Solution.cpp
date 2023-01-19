#include <iostream>
#include <string>
#include <algorithm>

int ClampToRange(int idx, const std::string& s) {
    return std::max(0, std::min((int)s.length(), idx));
}

bool CheckNeighbors(int idx, const std::string& s) {
    bool Prev = (s[ClampToRange(idx - 1, s)] == '1');
    bool Next = (s[ClampToRange(idx + 1, s)] == '1');

    return Prev ^ Next;
}

int main() {
    int t;
    std::cin >> t;

    for(int i = 0; i < t; i++) {
        int n, m;
        std::cin >> n >> m;
        std::cin.ignore();

        std::string Life;
        Life.reserve(n);
        std::getline(std::cin, Life);

        bool GameUpdate = true;
        std::string NextTick = Life;
        for(int Tick = 0; Tick < m && GameUpdate; Tick++) {
            GameUpdate = false;
            for(int CellIndex = 0; CellIndex < Life.length(); CellIndex++) {
                if(CheckNeighbors(CellIndex, Life)) {
                    NextTick[CellIndex] = '1';
                    GameUpdate = true;
                }
            }
            std::copy(NextTick.begin(), NextTick.end(), Life.begin());
        }

        std::cout << Life << '\n';
    }
}