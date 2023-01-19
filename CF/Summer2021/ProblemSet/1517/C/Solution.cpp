#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> Board(n);
    int SizeBuilder = n;
    for(auto& Vec : Board) {
        Vec.resize(SizeBuilder);
        std::fill_n(Vec.begin(), SizeBuilder, 0);
        SizeBuilder--;
    }

    for(int i = 0; i < n; i++) {
        int k;
        std::cin >> k;

        int x = i;
        int y = n - i - 1;
        for(int j = 1; j <= k; j++) {
            Board[x][y] = k;
            if(j != k) {
                if(x != 0 && Board[x - 1][y] == 0) {
                    x--;
                } else if(y != 0 && Board[x][y - 1] == 0) {
                    y--;
                } 

            }

        }
    }

    int NumCols = 1;
    for(int i = n - 1; i >= 0; i--) {
        for(int j = 0; j < NumCols; j++) {
            std::cout << Board[j][i] << ' ';
        }
        NumCols++;
        std::cout << '\n';
    }

    return 0;
}