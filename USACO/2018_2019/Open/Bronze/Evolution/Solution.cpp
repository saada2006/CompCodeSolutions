#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

#include <cstdio>
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

using namespace std;

/*
If we take a look at the tree structure, we realize this is almost like a binary tree:
1) Some cows get a new feature and some do not
2) All cows get a new feature

From now own, I'll represent each property as a bit (since there are, at most, 24 or 25)

We can say for each property, it has n descenandants
let us define a common property as a property that exists among all cows in that property's subtree

Then for each property, there must exist a sibling proprty, which shares the same common proprties except that property but differs in the property itself
This is just a very difficult impl problem
*/

#include <bitset>

int main() {
    int n;
    cin>>n;

    int numProps = 0;
    map<string, int> shiftMappings;
    vector<int> properties(n);

    for(int i = 0; i < n; i++) {
        int m;
        cin >> m;
        int enabled = 0;
        for(int j = 0; j < m; j++) {
            string s;
            cin >> s;
            int& nameShift = shiftMappings[s];
            if(nameShift == 0) {
                nameShift = numProps;
                numProps++;
            }

            int bitVal = (1 << nameShift);
            enabled = enabled | bitVal;
        }
        properties[i] = enabled;
        bitset<8> bout (enabled);
        cout << bout << '\n';
    }

    cout << "asdadsd\n";

    vector<vector<int>> backMappings(numProps);
    vector<int> commonProps(numProps);
    for(int i = 0; i < numProps; i++) {
        int checkBit = (1 << i);
        int shared = INT32_MAX;
        for(int j = 0; j < n; j++) {
            if((properties[j] & checkBit) != 0) {
                backMappings[i].push_back(j);
                shared = (shared & properties[j]);
            }
        }
        commonProps[i] = shared - checkBit;
        bitset<8> bout(commonProps[i]);
        cout << bout << '\n';
        cout << commonProps[i] << '\n';
    }

    // find a sibling property (which is defined as any property that has the same common property)
    // if none exists, then that means 1 of 2 things: we have no sibling in the evolution tree or we have an illogical evolution tree
    // to check which one it is, we have to search if there exists a property which can be see as the parent of our current node

    bool logicalTree = true;

    for(int i = 0; i < numProps; i++) {
        // find a sibling
        int siblingIdx = -1;
        for(int j = 0; j < numProps; j++) {
            if(i == j) {
                continue;
            }

            if(commonProps[i] == commonProps[j]) {
                siblingIdx = j;
                break;
            }
        }

        if(siblingIdx == -1) {
            cout << "no prop found for " << i << '\n';
            // check if parent exists
            // if we add the check bit of the parent to the property, then it should match our property
            bool noParent = true;
            int parentBit = 1;
            for(int j = 0; j < numProps; j++) {
                if(i == j) {
                    continue;
                }

                if(commonProps[i] == commonProps[j] + parentBit) {
                    noParent = false;
                    break;
                }
                parentBit = (parentBit << 1);
            }

            if(noParent) {
                logicalTree = false;
                break;
            }
        }
    }

    cout << (logicalTree ? "yes" : "no") << '\n';
}