#include <iostream>
#include <vector>

void Search(int& Counter, int y, const std::vector<std::vector<bool>>& ReservedPositions, std::vector<bool>& Col, std::vector<bool>& Diag0, std::vector<bool>& Diag1) {
    if(y == 8) {
        Counter++;
    } else {
        for(int x = 0; x < 8; x++) {
            if(Col[x] || Diag0[x + y] || Diag1[7 + x - y] || ReservedPositions[y][x]) {
                continue;
            } else {
                Col[x] = Diag0[x + y] = Diag1[7 + x - y] = true;
                Search(Counter, y + 1, ReservedPositions, Col, Diag0, Diag1);
                Col[x] = Diag0[x + y] = Diag1[7 + x - y] = false;
            }
        }
    }
}

int main() {
    std::vector<std::vector<bool>> ReservedPositions(8);
    for(auto& bvec : ReservedPositions) {
        std::string s;
        std::cin >> s;
        bvec.resize(8);

        for(int i = 0; i < 8; i++) {
            bvec[i] = (s[i] == '*');
        }
    }

    std::vector<bool> Col(8), Diag0(8), Diag1(8);
    int Counter = 0;
    Search(Counter, 0, ReservedPositions, Col, Diag0, Diag1);
    std::cout << Counter << '\n';
    return 0;
}