#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define BOARD_SIZE 1001
bool board[BOARD_SIZE][BOARD_SIZE];

int hasCow(int x, int y) {
    return ((x >= 0 && y >= 0 && x < BOARD_SIZE && y < BOARD_SIZE && board[x][y]) ? 1 : 0);
}

int cowCount(int x, int y) {
    return hasCow(x + 1, y) + hasCow(x - 1, y) + hasCow(x, y + 1) + hasCow(x, y - 1);
}

int comfy(int x, int y) {
    return ((hasCow(x, y) && cowCount(x, y) == 3) ? 1 : 0);
}

int currComfy(int x, int y) {
    return comfy(x, y) + comfy(x + 1, y) + comfy(x - 1, y) + comfy(x, y + 1) + comfy(x, y - 1);
}

int main() {
    int n;
    cin >> n;

    for(int i = 0; i < BOARD_SIZE; i++) 
        fill_n(board[i], BOARD_SIZE, false);

    int tot = 0;

    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;

        int bfr = currComfy(x, y);
        board[x][y] = true;
        int afr = currComfy(x, y);
        //for(int j = 0; j < 10; j++) {
        //    for(int k = 0; k < 10; k++) {
        //        cout << board[k][j];
        //    }
        //    cout << '\n';
        //}

        tot += afr - bfr;
        cout << tot << '\n';
    }

    return 0;
}