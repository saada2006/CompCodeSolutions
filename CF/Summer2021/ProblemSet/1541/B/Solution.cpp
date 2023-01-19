#include <iostream>
#include <vector>

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> Arr(n);
    for(int& x : Arr) {
        std::cin >> x;
    }

    int NumPleasantPairs = 0;
    for(int i = 0; i < n; i++) {
        int i1 = i + 1;
        for(int j = Arr[i] - i1; j <= n; j += Arr[i]) {
            int j0 = j - 1;
            if(i < j0 && Arr[i] * 1ULL * Arr[j0] == i1 + j) {
                NumPleasantPairs++;
            }
        }
    }

    std::cout << NumPleasantPairs << '\n';
}

int main() {
    int t;
    std::cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}

/*
    for(int i = 0; i < n; i++) {
        int i1 = i + 1;
        int ai = Arr[i];

        int Upper = ai * ((i1 + ai - 1) / ai);
        int Lower = ai * (i1 / ai);
        int j = Lower + Upper - i1;
        if(j <= i) {
            j += ai;
        }

        while(j <= n) {
            int j0 = j - 1;
            int aj = (i1 + j) / ai;

            if(Arr[j0] == aj) {
                PleasantPairs++;
            }

            j += ai;
        }
    }
*/