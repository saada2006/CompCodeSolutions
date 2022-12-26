#include <iostream>
#include <cstdio>
void InitIO(const char* FileName) {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    
    constexpr std::size_t BufferSize = 256;
    char StrBuf[BufferSize];

    StrBuf[0] = '\0';
    std::snprintf(StrBuf, BufferSize, "%s.in", FileName);
    std::freopen(StrBuf, "r", stdin);

    StrBuf[0] = '\0';
    std::snprintf(StrBuf, BufferSize, "%s.out", FileName);
    std::freopen(StrBuf, "w+", stdout);    
}

#include <vector>
#include <string>
#include <algorithm>

int n, k;
std::string moves;

/*
Suppose bessie is initially using the variable state as her move

We have an array of remaining states and how many moves left and how many points scored

std::vector<int[20]> scored

At each step we can choose to change the state or keep it
*/

// I hate pairs, I love structs.
struct State {
    char move;
    int score;

    State() : move(0), score(0) {}
};

int solve(char initial) {
    std::vector<State[20]> scored(n);

    State start;
    start.move = initial;
    start.score = 0;

    
}


int main() {
    std::cin >> n >> k;

    for(int i = 0; i < n; i++) {
        char c;
        std::cin >> c;
        moves.push_back(c);
    }

    // Bessie can have different initial states, and dp will operate on each of this, so they have to be solves seperately
    int h = solve('H');
    int p = solve('P');
    int s = solve('S');
    
    std::cout << std::min(h, std::min(p, s)) << '\n';
}