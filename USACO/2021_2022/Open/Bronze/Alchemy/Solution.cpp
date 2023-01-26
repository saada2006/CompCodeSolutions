#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

// what does it take to make 1 unit of metal N? it's materials of course
// so we try to create one unit of each metal required, and if we fail, we are done

bool craft(int metal, vector<int>& metals, const vector<vector<int>>& recipes) {
    //cout << "Crafting metal " << metal << '\n';
    // if we have the metal, then craft
    if(metal != metals.size() - 1 && metals[metal] > 0) {
        metals[metal]--;
        return true;
    } else {
        // craft, if we can, else our process is done
        if(recipes[metal].empty()) {
            return false;
        }

        bool crafted = true;
        for(int ingredient : recipes[metal]) {
            if(!craft(ingredient, metals, recipes)) {
                crafted = false;
                break;
            }
        }

        return crafted;
    }
}

int main() {

    int n;
    cin >> n;

    vector<int> metals(n);
    for(int& x : metals) {
        cin >> x;
    }

    int k;
    cin >> k;

    vector<vector<int>> recipes(n);
    for(int i = 0; i < k; i++) {
        int l, m;
        cin >> l >> m;
        l--;

        recipes[l].resize(m);
        for(int& x : recipes[l]) {
            cin >> x;
            x--;
        }
    }

    while(craft(n - 1, metals, recipes)) {
        metals[n - 1]++;
    }
    cout << metals[n - 1] << '\n';
}