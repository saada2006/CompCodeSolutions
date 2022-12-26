#include <iostream>
#include <vector>
#include <algorithm>

/*
We can solve this brute force by assuming that one cow is telling the exact location of bessie
We then need to figure out the number of cows who are lying by seeing how many cows' statement is inconsistent with the truth telling cow

*/

int main() {
    int n;
    std::cin >> n;

    std::vector<int> gequal, lequal;

    for(int i = 0; i < n; i++) {
        char c;
        int p;
        std::cin >> c >> p;
        if(c == 'G') {
            gequal.push_back(p);
        } else {
            lequal.push_back(p);
        }
    }

    std::vector<int> merge;
    merge.insert(merge.end(), gequal.begin(), gequal.end());
    merge.insert(merge.end(), lequal.begin(), lequal.end());

    // n is at most 1000 so we don't need binary search or a two pointer approach to solve this problem; we can just count the number of cows in a o(n^2) solution
    int minLiars = INT32_MAX;
    for(int truth : merge) {
        int numLiars = 0;

        for(int g : gequal) {
            if(truth < g) {
                numLiars++;
            }
        }

        for(int l : lequal) {
            if(truth > l) {
                numLiars++;
            }
        }

        minLiars = std::min(minLiars, numLiars);
    }

    std::cout << minLiars << '\n';
}