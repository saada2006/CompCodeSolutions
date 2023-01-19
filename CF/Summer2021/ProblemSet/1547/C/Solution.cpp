#include <iostream>
#include <vector>

void solve() {
    int k, n, m;
    std::cin >> k >> n >> m;

    std::vector<int> Mono(n), Poly(m);
    for(int& x : Mono) {
        std::cin >> x;
    }
    for(int& x : Poly) {
        std::cin >> x;
    }

    std::vector<int> Actions;
    Actions.reserve(n + m);

    int PolyIdx = 0;
    for(const int Edit : Mono) {
        if(Edit == 0) {
            k++;
        } else if(Edit > k) {

            for(; PolyIdx < m; PolyIdx++) {
                if(Poly[PolyIdx] == 0) {
                    k++;
                } else if(Poly[PolyIdx] > k) {
                    break;
                }
                Actions.push_back(Poly[PolyIdx]);
            }

            if(Edit > k) {
                std::cout << -1 << '\n';
                return;
            }

        }
        Actions.push_back(Edit);
    }

    for(; PolyIdx < m; PolyIdx++) {
        if(Poly[PolyIdx] == 0) {
            k++;
        } else if(Poly[PolyIdx] > k) {
            std::cout << -1 << '\n';
            return;
        }
        Actions.push_back(Poly[PolyIdx]);
    }

    for(const int Edit : Actions) {
        std::cout << Edit << ' ';
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