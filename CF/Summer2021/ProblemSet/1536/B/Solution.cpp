#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

void Generate(std::vector<std::string>& Pregen, std::string& Build) {
    if(Build.size() > 3) {
        return;
    } 

    for(char c = 'a'; c <= 'z'; c++) {
        Build.push_back(c);
        Pregen.push_back(Build);
        Generate(Pregen, Build);
        Build.pop_back();
    }
}

std::vector<std::string> PregeneratedCombinations;

void solve() {
    int n;
    std::string Message;
    std::cin >> n >> Message;

    for(const std::string& MEX : PregeneratedCombinations) {
        if(Message.find(MEX) == std::string::npos) {
            std::cout << MEX << '\n';
            return;
        }
    }
}

int main() {
    PregeneratedCombinations.reserve(26 * 27 * 28);
    std::string MEXB;
    Generate(PregeneratedCombinations, MEXB);
    std::sort(PregeneratedCombinations.begin(), PregeneratedCombinations.end(),
        [](const std::string& S0, const std::string& S1) -> bool {
            if(S0.size() == S1.size()) {
                return S0 < S1;
            } else {
                return S0.size() < S1.size();
            }
        }
    );

    int t;
    std::cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}