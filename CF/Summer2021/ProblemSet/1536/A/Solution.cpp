#include <iostream>
#include <algorithm>
#include <vector>

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> Arr(n);
    for(int& x : Arr) {
        std::cin >> x;
    }
    std::sort(Arr.begin(), Arr.end());

    bool Change = true;
    while(Change && Arr.size() <= 300) {
        Change = false;

        for(int i = 0; i < Arr.size(); i++) {
            for(int j = i + 1; j < Arr.size(); j++) {
                int Diff = Arr[j] - Arr[i];
                auto IterPos = std::lower_bound(Arr.begin(), Arr.end(), Diff);
                if(IterPos == Arr.end() || *IterPos != Diff) {
                    Arr.insert(IterPos, Diff);
                    Change = true;
                    break;
                }
            }
            if(Change) {
                break;
            }
        }
    }

    if(Arr.size() <= 300) {
        std::cout << "YES\n" << Arr.size() << '\n';
        for(const int x : Arr) {
            std::cout << x << ' ';
        }
        std::cout << '\n';
    } else {
        std::cout << "NO\n";
    }
}

int main() {
    int t;
    std::cin >> t;

    while(t--)
        solve();

    return 0;
}