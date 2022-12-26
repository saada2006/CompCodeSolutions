#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int plant(char c, int i, int k, int& maxend, string& grass) {
    int loc = i + k;
    if(loc + 1 >= maxend){
        maxend--;
        loc = maxend;
    }
    grass[loc] = c;
    return loc + k;
}

void solve() {
    int n, k;
    cin >> n >> k;

    string cows;
    cin >> cows;

    string grass;
    grass.resize(n);
    fill(grass.begin(), grass.end(), '.');

    int next_hungry_g = -1, next_hungry_h = -1;
    int maxend = n;
    int plant_counter = 0;
    for(int i = 0; i < n; i++) {
        if(cows[i] == 'G' && i > next_hungry_g) {
            next_hungry_g = plant('G', i, k, maxend, grass);
            plant_counter++;
        } else if(cows[i] == 'H' && i > next_hungry_h) {
            next_hungry_h = plant('H', i, k, maxend, grass);
            plant_counter++;
        }
    }

    cout << plant_counter << '\n' << grass << '\n';
}

int main() {
    int t;
    cin >> t;

    while(t--) solve();
}