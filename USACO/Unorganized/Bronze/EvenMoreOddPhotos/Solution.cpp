#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    int NumCounter[2] {0, 0};
    for(int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        NumCounter[x % 2]++;
    }

    int NumGroups = 0;
    int GroupType = 0;
    while(true) {
        if(GroupType == 0) {
            if(NumCounter[0]) {
                NumCounter[0]--;
            } else if(NumCounter[1] >= 2) {
                NumCounter[1]-=2;
            } else {
                if(NumCounter[1]) {
                    // merge this one with the previous group, making an even group
                    // to keep the order we should merge that group with the group behind it
                    NumGroups--;
                }
                break;
            }
        } else {
            if(NumCounter[1]) {
                NumCounter[1]--;
            } else {
                break;
            }
        }

        NumGroups++;
        GroupType = 1 - GroupType;
    }

    std::cout << NumGroups << '\n';

    return 0;
}