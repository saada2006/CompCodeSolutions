#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

/*

An observation we can make is that to make 1 unit of n, we can go down the recipe tree and see how many of the rudimentry metals (the ones we cannot "craft") we need
We can then count the maximum number of metal n we can craft by dividing the avaible amount by the rudiementry amount

Note: we need to be careful with useless metals taht cannot be crafted into higher metals
*/

void collapse(std::vector<int>& single, const std::map<int, std::vector<int>>& recipies) {
    for(auto iter = recipies.rbegin(); iter!= recipies.rend(); iter++) {
        // decraft into other decraftable or rudimentary metals
        int& count = single[iter->first];
        for(int x : iter->second) {
            single[x] += count;
        }
        count = 0;
    }
}

int main() {
    int n;
    std::cin >> n;

    std::vector<int> metals(n);

    for(int& x : metals) {
        std::cin >> x;
    }

    int k;
    std::cin >> k;
    std::map<int, std::vector<int>> recipies;
    for(int i = 0; i < k; i++) {
        int l, m;
        std::cin >> l >> m;
        l--;

        recipies[l].resize(m);
        for(int& x : recipies[l]) {
            std::cin >> x;
            x--;
        }
    }


    collapse(metals, recipies);
    std::vector<int> single(n);
    single.back() = 1;
    collapse(single, recipies);

    int div = INT32_MAX;
    for(int i = 0; i < n; i++) {
        if(single[i] != 0){
            div = std::min(div, metals[i] / single[i]);
        }
    }

    std::cout << div << '\n';
    return 0;
}