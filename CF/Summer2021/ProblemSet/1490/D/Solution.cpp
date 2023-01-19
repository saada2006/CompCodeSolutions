#include <iostream>
#include <vector>

int FindMax(const std::vector<int>& Tree, int L, int R) {
    int I = L;
    for(int Iter = L + 1; Iter < R; Iter++) {
        if(Tree[Iter] > Tree[I]) {
            I = Iter;
        }
    }
    return I;
}

void AssignLevels(const std::vector<int>& Tree, std::vector<int>& Depth, int L, int R, int D) {
    if(L == R) {
        return;
    }
    int Split = FindMax(Tree, L, R);
    Depth[Split] = D;
    int ND = D + 1;
    AssignLevels(Tree, Depth, L,     Split, ND);
    AssignLevels(Tree, Depth, Split + 1, R, ND);
}

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> Tree(n);
    for(int& x : Tree) {
        std::cin >> x;
    }

    std::vector<int> Depth(n);
    AssignLevels(Tree, Depth, 0, n, 0);

    for(const int D : Depth) {
        std::cout << D << ' ';
    }
    std::cout << '\n';
}

int main() {
    int t;
    std::cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}