#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

/*
Everything about this problem screams "graph!"

First, let's block out the noise: the ith cow does not have a wish list of items it likes less than or equal to gift i. Let's redefine this "I want better than I current have" back to as the wish list
Second, a cow will only accept a trade from a cow if it is on its wish list (which can be done efficiently using binary search)
Third, a cow can only accept a gift if it gives a gift, meaning that our end result of the exchange will look like a functional graph (when including only the cows that exchange)

Once we have prased the graph from input, our data is basically a graph representing, in order of preference, which cow would trade with who
If we are going to brute force this, the first thing we should do is eliminate bad swaps
If a cow is giving a gift to another cow, then that gift should be on the wishlist of the cow that is being given the gift
The cow that is giving, in turn, should expect a gift on its wishlist (otherwise, it would be left with a worse or no gift)

Let's be careful about what this question is asking: it is after any reassignment, so the answer for one cow may be inconsistent with another because the answers were generated using different reassignments 

For each cow, we can try to generate a solution where the cow gets its best gift and all others get bad ones
The moment we generate a solution, we are done

Suppose a cow gets a gift from some cow who has a gift on the recieving cow's wishlist
Then we have two tasks:
1. Make sure the old gift of the receiving cow goes somewhere
2. Make sure the giving cow gets a gift
And now we have our problem, formulated into competitive programmer terms: does a cycle exist between nodes a and b? 
Since I never really bothered reading graph algorithms that much, I will have to devise on my own (using dp)

If a cycle exists between nodes a and b, then a cycle between all nodes on that path exists
Suppose we find a path via dfs: then we can iterate through all nodes on it and say a cycle exists between them
*/

int main() {
    int n;
    cin >> n;

    vector<vector<int>> wishlists(n);
    for(int i = 0; i < n; i++) {
        auto& v = wishlists[i];
        bool done = false;
        for(int j = 0; j < n; j++) {
            int x;
            cin >> x;
            x--;
            if(!done) {
                if(x == i) {
                    done = true;
                } 
                else v.push_back(x); 
            }
        }
    }

    vector<int> best(n);
    for(int i = 0; i < n; i++) {
        best[i] = i;
    }

    vector<int> visited(n);
    fill_n(visited.begin(), n, -1);

    vector<vector<bool>> matrix(n);
    for(int i = 0; i < n; i++) {
        matrix[i].resize(n);

        queue<int16_t> postponed;
        postponed.push(i);
        while(!postponed.empty()) {
            int x = postponed.front();
            postponed.pop();

            for(int y : wishlists[x]) {
                if(visited[y] == i) {
                    continue;
                } else {
                    visited[y] = i;
                    matrix[i][y] = true;
                    postponed.push(y);
                }
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j : wishlists[i]) {
            bool cycle = matrix[i][j] && matrix[j][i];
            if(cycle) {
                best[i] = j;
                break;
            }
        }
    }

    for(int x : best) {
        cout << x + 1 << '\n';
    }
}