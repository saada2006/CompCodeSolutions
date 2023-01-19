#include <iostream>
#include <vector>
#include <algorithm>

/*
Idealy you get 100 point stages and illya gets 0
*/

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> User, Ilya;

    User.reserve(n * 4);
    Ilya.reserve(n * 4);

    User.resize(n);
    Ilya.resize(n);

    for(int& x : User) {
        std::cin >> x;
    }
    for(int& x : Ilya) {
        std::cin >> x;
    }

    std::sort(User.begin(), User.end());
    std::sort(Ilya.rbegin(), Ilya.rend());

    int CurScore = 0, OppScore = 0;
    int k = n - (n / 4);
    for(int i = 0; i < k; i++) {
        CurScore += User[i];
        OppScore += Ilya[n - i - 1];
    }

    int PrevK = k;
    int NumStagesAdded = 0;
    while(CurScore < OppScore) {
        
    }

    std::cout << NumStagesAdded << '\n';
}

int main() {
    int t;
    std::cin >> t;

    while(t--) {

    }

    return 0;
}