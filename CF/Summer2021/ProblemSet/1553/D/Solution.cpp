#include <iostream>
#include <string>

void solve() {
    std::string Dst, Src;
    std::cin >> Src >> Dst;

    int SrcIdx = Src.size() - 1;
    for(auto RIter = Dst.rbegin(); RIter != Dst.rend(); RIter++) {
        char Search = *RIter;

        while(SrcIdx >= 0) {
            if(Src[SrcIdx] == Search) {
                break;
            } else {
                SrcIdx -= 2;
            }
        }

        if(SrcIdx < 0 || Src[SrcIdx] != Search) {
            std::cout << "NO\n";
            return;
        }
        SrcIdx--;
    }

    std::cout << "YES\n";
}

int main() {
    int t;
    std::cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}