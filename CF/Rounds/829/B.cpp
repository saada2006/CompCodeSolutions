#include <iostream>

using namespace std;

// I think we can establish a rough upper bound using n/2

#include <algorithm>

void brute_force5() {
    int arr[] = {1, 2, 3, 4, 5};

    int best_arr[5];
    int best_score = 0;

    do {
        int score = 0;
        for(int i = 1; i < 5; i++) {
            int diff = abs(arr[i] - arr[i - 1]);
            score += diff;
        }

        if(score > best_score) {
            best_score = score;
            copy(arr, arr + 5, best_arr);
        }
    } while(next_permutation(arr, arr + 5));

    for(int i = 0; i < 5; i++)
        cout << best_arr[i] << ' ';
}

void solve() {
    int n;
    cin >> n;

    int a = n / 2, b = 2 * a;

    while(a > 0) {
        cout << a << ' ' << b << ' ';
        a--;
        b--;
    }

    if(n % 2 == 1)
        cout << n;

    cout << '\n';   
}

int main() {
    int n;
    cin >> n;

    while(n--)
        solve();
}