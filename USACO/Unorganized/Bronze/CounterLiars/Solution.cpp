#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> Greater, Lesser;

    for(int i = 0; i < n; i++) {
        char c;
        int p;
        std::cin >> c >> p;
        if(c == 'G')
            Greater.push_back(p);
        else
            Lesser.push_back(p);
    }

    std::sort(Greater.begin(), Greater.end());
    std::sort(Lesser.rbegin(), Lesser.rend());

    int maxTruthTellers = 0;

    for(int i = 0; i < Lesser.size(); i++) {
        int truthGreater = 0;
        int testPosition = Lesser[i];
        for(int p : Greater) {
            if(testPosition < p) {
                break;
            }
            truthGreater++;
        }
        maxTruthTellers = std::max(maxTruthTellers, 1 + i + truthGreater);
    }

    std::cout << n - maxTruthTellers << std::endl;

}