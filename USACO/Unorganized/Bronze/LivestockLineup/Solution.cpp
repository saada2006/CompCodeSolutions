// Copy paste for fast USACO file I/O redirection
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
    std::freopen(StrBuf, "w", stdout);    
}

#include <vector>
#include <algorithm>

const std::vector<std::string> LexographicalOrdering = {
    "Beatrice", "Belinda", "Bella", "Bessie", "Betsy", "Blue", "Buttercup", "Sue"
};

bool Adj[8][8];

int main() {
    InitIO("lineup");

    for(int i = 0; i < 8; i++) {
        std::fill_n(Adj[i], 8, false);
    }

    int n;
    std::cin >> n;
    
    for(int i = 0; i < n; i++) {
        std::string c0, c1, s;
        std::cin >> c0 >> s >> s >> s >> s >> c1;
        int x = std::distance(LexographicalOrdering.begin(), std::find(LexographicalOrdering.begin(), LexographicalOrdering.end(), c0));
        int y = std::distance(LexographicalOrdering.begin(), std::find(LexographicalOrdering.begin(), LexographicalOrdering.end(), c1));
        Adj[x][y] = Adj[y][x] = true;
    }

    int CurrentOrder[8] = {
        0, 1, 2, 3, 4, 5, 6, 7,
    };

    do {
        bool ConstrainstsSatisfied = true;
        for(int i = 0; ConstrainstsSatisfied && i < 8; i++) {
            int Current = CurrentOrder[i];

            int Next, Prev;

            if(i == 0) {
                Prev = -1;
                Next = CurrentOrder[1];
            } else if(i == 7) {
                Prev = CurrentOrder[6];
                Next = -1;
            } else {
                Prev = CurrentOrder[i - 1];
                Next = CurrentOrder[i + 1];
            }

            // Check whether if the entries true in adj match 
            for(int j = 0; j < 8; j++) {
                if(Adj[Current][j] && Prev != j && Next != j) {
                    ConstrainstsSatisfied = false;
                    break;
                }
            }
        }

        if(ConstrainstsSatisfied) {
            break;
        }
    } while(std::next_permutation(CurrentOrder, CurrentOrder + 8));

    for(int i = 0; i < 8; i++) {
        std::cout << LexographicalOrdering[CurrentOrder[i]] << '\n';
    }
}

/*
Basic idea:
We can build multiple possible orderings based on the given hints
For each of these orderings 
Also strings are bad let's replace them with their lexographically ordered index
*/

/*

std::vector<std::pair<int, int>> OrderingHints;
std::vector<std::vector<int>> Orderings;

void Search(const int n, int idx, std::vector<int>& CurrentOrder) {
    if(idx == n) {
        bool Appearance[7];
        std::fill_n(Appearance, 7, false);
        for(int i = 0; i < CurrentOrder.size(); i++) {
            Appearance[CurrentOrder[i]] = true;
        }
        int NextInsert = 0;
        std::vector<int> CurCpy = CurrentOrder;
        for(int i = 0; i < 7; i++) {
            for(;NextInsert < 7 && !Appearance[NextInsert]; NextInsert++);
            if(CurrentOrder[i] > NextInsert) {
                CurCpy.insert(CurCpy.begin() + i + 1, NextInsert);
            }
        }
        Orderings.push_back(CurCpy);
    } else {
        int Next = idx + 1;
        if(idx == 0) {
            CurrentOrder.push_back(OrderingHints.front().first);
            CurrentOrder.push_back(OrderingHints.front().second);
            Search(n, Next, CurrentOrder);
            CurrentOrder.clear();
            CurrentOrder.push_back(OrderingHints.front().second);
            CurrentOrder.push_back(OrderingHints.front().first);
            Search(n, Next, CurrentOrder);
            CurrentOrder.clear();
        } else {
            // If the new ordering hint contains a hint refrencing a cow already in the order, then that cow MUST be either on the front or back of the vector
        }
    }
}

int main() {
    InitIO("lineup");

    int n;
    std::cin >> n;

    OrderingHints.resize(n);
    for(auto& Order : OrderingHints) {
        std::string c0, c1, s;
        std::cin >> c0 >> s >> s >> s >> s >> c1;
        Order.first  = std::distance(LexographicalOrdering.begin(), std::find(LexographicalOrdering.begin(), LexographicalOrdering.end(), c0));
        Order.second = std::distance(LexographicalOrdering.begin(), std::find(LexographicalOrdering.begin(), LexographicalOrdering.end(), c1));
    }

    return 0;
}
*/