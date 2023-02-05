#include <vector>
#include <iostream>
#include <map>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for(int& x : a) {
        cin >> x;
    }


    vector<long long> prefix(n + 1);
    map<long long, long long> count;
    prefix[0] = 0;
    count[0]++;
    long long numarr = 0;
    for(int i = 1; i <= n; i++) {
        prefix[i] = a[i - 1] + prefix[i - 1];
        long long sub = prefix[i] - x;
        numarr += count[sub];
        count[prefix[i]]++;

    }

    cout << numarr << '\n';

}