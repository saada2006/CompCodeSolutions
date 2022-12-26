#include <iostream>
#include <vector>
#include <algorithm>

/*
Based on the input size, our target complexity is at most o(nlogn)
This implies we might be doing sorting, and dp is not a silver topic so we know we need to come up with a greedy solution
We also need to remember that a multiple cows may be the buddy of one cow

If we think about it, the permuation does not change the buddy of a cow, because cow p_i will still visit cow a_p_i
An optimal permutation of 1...N will try to maximize the number of moos by making sure the order the cows are visited in is optimal
The property of an optimal ordering is that the minimum number of moos are lost because some cow wants to visit a departed cow
If a cow can gain x number of moos by staying, and y number of points by visiting, then x should be minimized

Let's think about this another way. We can see that this is actually one big graph problem, where the edges are all possible connetions between i and a_i
An interesting property of this graph is that for n nodes there are n edges, so the permuation problem for the buddies can be viewed as the permuations for the edges

Now I'm beginning to think that I am thinking this the wrong way, because when I get stuck and think for a long time, my angle of attack on the problem is usually wrong altogether

Okay I did a bit of cheating and looked at USACO guide, a successor graph perfectly fits this problem because each cow has exactly 1 buddy

*/

/*
Alright, thanks for the help from the kind people on the MSJ CS server, I now know this is a cycle detection problem
We simply need to, for each cycle and the "strands" that lead into it, find an optimal place to start the mooing stuff
The lone strands go first to make our life easier, since they are not cyclic and so there is no moos to be lost
Then, we need to find the cow with the least moos gained and start there
If we are smart enough to design an algorithm that does not visit each node more than once, we have o(n) complexity

If we scratch our head enough, we know the upper bound for moos can be the sum of all moos
Then we have to subtract the cows which we have decided must start first
To find these cows, we detect a cycle and record it
Then, for each cycle, we find the best cow to start it
To find the best cow to start at, we have the sum up all the weights of the edges leading to the cow, since that is the moos lost if the cow starts first
Once we have the best cow, we subtract the moos we can gain from it

(Also based on the problem statement, the graph is garunteed to contain at least one cycle. Perhaps this is an interesting propery of functional graphs)

Basically, each a_i, v_i is a weighted edge between buddy i and a_i
If buddy i visits a_i, the cow makes v_i moos
Then the number of moos a cow can make by being visited is the sum of all v_is that point to it
*/

int main() {
    int64_t n;
    std::cin >> n;
    std::vector<std::pair<int64_t, int64_t>> graph(n);
    // Find upper bound for total moos
    int64_t sum = 0;
    for(auto& p : graph) {
        std::cin >> p.first >> p.second;
        p.first--;
        sum += p.second;
    }

    std::vector<int64_t> gain(n);

    // Detect all cycles
    int64_t minTotalLoss = 0; // total minimuzed loss
    std::vector<int> searched(n);
    std::fill(searched.begin(), searched.end(), -1); // mark each node as unvisited (in this context visiting has to do with the search, not with cows)
    for(int i = 0; i < n; i++) {
        // If we have processed this node already, don't bother
        if(searched[i] != -1) {
            continue;
        }

        bool cyclic;
        int marker = i * 2; 
        int j = i;
        while(true) {
            searched[j] = marker;
            j = graph[j].first; // move from buddy i to buddy a_i
            if(searched[j] != -1) {
                // we have reached already processed stuff
                cyclic = (searched[j] == marker);
                break;
            }
        }


        if(cyclic) {
            // evaluate the gain
            int k = j;
            while(true) {
                int next = graph[k].first;
                gain[next] = graph[k].second;
                k = next;
                if(k == j) {
                    break;
                }
            }

            int64_t minLoss = INT64_MAX;
            while(true) {
                minLoss = std::min(minLoss, gain[k]);
                k = graph[k].first; // move from buddy i to buddy a_i
                if(k == j) {
                    break;
                }
            }
            minTotalLoss += minLoss;
        }
    }


    std::cout << sum - minTotalLoss << '\n';
    return 0;
}