#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

int recurse(const vector<vector<int>>& graph, int node) {
    int curblame = graph[node].size();
    for(int x : graph[node]) {
        curblame += recurse(graph, x);
    }
    return curblame;
}

int main() {
    int n;
    cin >> n;

    vector<tuple<char, int, int>> cows(n);
    for(auto& t : cows)
        cin >> get<0>(t) >> get<1>(t) >> get<2>(t);

    vector<tuple<int, int, int>> ruts; // time, stopped cow, stopper cow
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            // boring intersection logic

            if(get<0>(cows[i]) != get<0>(cows[j])) { // uneq dir
                int x, y;

                if(get<0>(cows[i]) == 'E') {
                    x = get<1>(cows[j]);
                    y = get<2>(cows[i]);
                } else {
                    x = get<1>(cows[i]);
                    y = get<2>(cows[j]);
                }

                int ti = (x - get<1>(cows[i])) + (y - get<2>(cows[i]));
                int tj = (x - get<1>(cows[j])) + (y - get<2>(cows[j]));


                if(ti < 0 || tj < 0 || ti == tj) {
                    continue;
                }

                //cout << "=========\n";
                //cout << get<1>(cows[i]) << ' ' << get<2>(cows[i]) << '\n';
                //cout << get<1>(cows[j]) << ' ' << get<2>(cows[j]) << '\n';
                //cout << x << ' ' << y << '\n';

                if(ti > tj) {
                    ruts.push_back(make_tuple(ti, i, j));
                } else if (tj > ti) {
                    ruts.push_back(make_tuple(tj, j, i));
                }
            } else if((get<0>(cows[i]) == 'E' && get<2>(cows[i]) == get<2>(cows[j])) || (get<0>(cows[i]) == 'N' && get<1>(cows[i]) == get<1>(cows[j]))) {
                int* die = nullptr;
                cout << *die << '\n';
            }
        }
    }

    sort(ruts.begin(), ruts.end());

    vector<bool> stopped(n);
    fill(stopped.begin(), stopped.end(), false);

    vector<vector<int>> blame(n);

    for(auto& r : ruts) {
        if(!stopped[get<1>(r)] && !stopped[get<2>(r)]) { // both cows should not stop before the time
            stopped[get<1>(r)] = true;

            blame[get<2>(r)].push_back(get<1>(r));
        }
    }
    
    for(int i = 0; i < n; i++) {
        cout << recurse(blame, i) << '\n';
        //if(i == 197) {
        //    cout << get<0>(cows[i]) << ' ' << get<1>(cows[i]) << ' ' << get<2>(cows[i]) << '\n';
        //    cout << get<0>(cows[blame[i][0]]) << ' ' << get<1>(cows[blame[i][0]]) << ' ' << get<2>(cows[blame[i][0]]) << '\n';
        //}
    }

}