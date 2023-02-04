#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    int n;
    cin >> n;
    //cout << "hello\n";

    vector<vector<int>> roads(n);
    for(int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        roads[a].push_back(b);
        roads[b].push_back(a);
    }

    // double cows until enough for each child of node
    int days = 0;
    
    vector<bool> infected(n);
    fill(infected.begin(), infected.end(), false);
    infected[0] = true;

    stack<int> uninfected;
    uninfected.push(0);
    while(!uninfected.empty()) {
        int curr = uninfected.top();
        uninfected.pop();

        
        int numInfected = 1;
        
        int numNeighbors = 0;//(curr == 0 ? roads[curr].size() : roads[curr].size() - 1);
        for(int next : roads[curr]) {
            if(!infected[next]) {
                numNeighbors++;
            }
        }


        while(numInfected < numNeighbors + 1) { // at least one remains at current barn
            numInfected *= 2;
            days++;
        }

        

        for(int next : roads[curr]) {
            if(!infected[next]) {
                uninfected.push(next);
                infected[next] = true;
                days++;
            }
        }
    }

    
    cout << days << '\n';
    return 0;
}