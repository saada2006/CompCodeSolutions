#include <iostream>
#include <cstdio>
#include <algorithm>

class Game {
public:
    Game(int pos) {
        Score = 0;
        Shell[0] = Shell[1] = Shell[2] = false;
        StartShell(pos);
    }
    
    void StartShell(int x) {
        Shell[x] = true;
    }

    void SwapShells(int x, int y) {
        std::swap(Shell[x], Shell[y]);
    }

    void MakeGuess(int x) {
        if(Shell[x]) {
            Score++;
        }
    }

    int GetScore(void) {
        return Score;
    }
private:
    int Score;
    bool Shell[3];
};

int main() {
    freopen("shell.in", "r", stdin);
    freopen("shell.out", "w", stdout);

    int n;
    std::cin >> n;

    Game A(0);
    Game B(1);
    Game C(2);

    for(int i = 0; i < n; i++) {
        int a, b, g;
        std::cin >> a >> b >> g;
        a--;
        b--;
        g--;

        A.SwapShells(a, b);
        A.MakeGuess(g);

        B.SwapShells(a, b);
        B.MakeGuess(g);

        C.SwapShells(a, b);
        C.MakeGuess(g);
    }

    int MaxScore = std::max(std::max(A.GetScore(), B.GetScore()), C.GetScore());
    std::cout << MaxScore;
    return 0;
}