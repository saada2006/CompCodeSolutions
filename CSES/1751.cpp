#include <iostream>
#include <vector>

/*
To solve this problem, we need to be aware that some nodes are not part of the cycle themselves but lead into it
We must also be aware that each node in the test case is garunteed to lead into a cycle or be a part of it

Good old DFS can be used to find the already visited nodes
Then we can remember the answer for each vertex along the path
*/

int main() {
    int n;
    std::cin >> n;
    std::vector<int> graph(n);
    for(int& x : graph) {
        std::cin >> x;
        x--;
    }

    std::vector<std::vector<int>> cycles;
    cycles.reserve(n);
    
    std::vector<bool> done(n); // if we already have a value for this vertex
    std::vector<int> states(n); // the value if we already have a value for the vertex
    for(int i = 0; i < n; i++) {
        if(done[i]) {
            continue;
        }

        // traverse into the graph
        bool endByPrecompute = false;
        int length = 0;
        int j = i;
        while(true) {
            length++;
            done[j] = true;
            j = graph[j];
            if(done[j]) {
                length += states[j];
                if(states[j] != 0) {
                    endByPrecompute = true;
                }
                break;
            }
        }

        // Now that our j is the endpoint of the graph, we need to retraverse
        bool decrement = true;
        int k = i;
        while(true) {
            states[k] = length;
            if(k == j) {
                if(endByPrecompute) {
                    break;
                } else {
                    if(decrement) {
                        decrement = false;
                    } else {
                        break;
                    }
                }
            }
            if(decrement) {
                length--;
            }
            k = graph[k];

        }
    }


    for(int x : states) {
        std::cout << x << ' ';
    }
}