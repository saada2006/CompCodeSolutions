#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> original(n);
    vector<int> location(n);
    for(int i = 0; i < n; i++){
        int& x = original[i];
        cin >> x;
        x--;
        location[x] = i;
    }

    vector<int> desired(n);
    for(int& x : desired) {
        cin >> x;
        x--;
    }

    vector<bool> record(n);

    int moves = 0;
    int j = 0;
    for(int i = 0; i < n; i++) {
        // decr only if consecutive array elems
        
        int expected = desired[i];
        // If there have been x moves to the front of the correctly positioned array, then the array index will be x behind
        int actual = original[j];
        if(expected != actual) {
            moves++;
            record[location[expected]] = true;
        } else {
            // go to next array element
            do {
                j++;
            } while(j < n && record[j]);
        }

    }

    cout << moves << '\n';
    return 0;
}