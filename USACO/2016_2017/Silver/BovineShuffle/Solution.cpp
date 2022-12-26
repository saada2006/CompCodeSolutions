#include <cstdio>
#include <iostream>
void InitIO(const char* FileName) {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    
    constexpr std::size_t BufferSize = 256;
    char StrBuf[BufferSize];

    StrBuf[0] = '\0';
    std::snprintf(StrBuf, BufferSize, "%s.in", FileName);
    std::freopen(StrBuf, "r", stdin);

    StrBuf[0] = '\0';
    std::snprintf(StrBuf, BufferSize, "%s.out", FileName);
    std::freopen(StrBuf, "w", stdout);    
}

/*
Simple functional graph problem:

The idea is to count each spot that is within a cycle
Since, in the beginning, all spots have a cow, we do not have to worry about the number of cows on the cycle
To count the number of such spots, we can traverse the graph starting from each of the spots
There are 4 possible states of a node

0: this node has not been touched yet
1: this node is currently part of a search path
2: this node is NOT part of a cycle
3: this node is part of a cycle

We then loop over the graph and increment for each 4 state. To assign these values, we start at node 1, set it to 1, and traverse through the graph and set it ti 1. 
If we come across a 0 state node, we include it in the search. If it comes across 1, we have found a cycle. If it comes across 2 or 3, our path is not cyclic
Once we have determined if it is cyclic or not, we traverse back into the graph to update the values

Complexity: o(n)
*/

#include <vector>

int main() {
    InitIO("shuffle");
    int n;
    std::cin >> n;
    std::vector<int> shuffle(n);
    for(int& x : shuffle) {
        std::cin >> x;
        x--; // 0-indexing
    }

    int answer = 0;
    std::vector<int> states(n);
    int abcd = 0;
    for(int i = 0; i < n; i++) {
        if(states[i] != 0) {
            continue;
        }

        // To stay o(n) and not start at a "tail" leading into a cycle, we have to mark the cycle end and start indices
        int j = i;
        while(true) {

            // Check if we have cycled
            if(states[j] == 2) {
                break;
            }
            // If we have run into another (a)cycle, then we are not cyclic
            if(states[j] == 1 || states[j] == -1) {
                break;
            }
            // Mark this node as part of the search and move on
            states[j] = 2;
            j = shuffle[j];
        }

        // retraverse the known cycle and mark it as such
        int k = i;
        int write = -1;
        while(states[k] == 2) {
            // if we reach j and we are not writing 1s, then write 1s, else break
            if(k == j) {
                if(write == -1) {
                    write = 1;
                } else {
                    break;
                }
            }
            states[k] = write;
            k = shuffle[k];
        }
    }

    for(int x : states) {
        if(x == 1) {
            answer++;
        }
    }

    std::cout << answer << '\n';
    return 0;
}