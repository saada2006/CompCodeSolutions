#include <iostream>
#include <stdio.h>

/*

Rephrase the problem: least taxis == least wasted space

4 gets own taxis (taxi++)

combine 3 with 1 until no 3s or 1s remain
combine 2s with 2s until a single or none 2 remains
all remaining 3s get their own taxi
add 2 to last taxi and combine 1s 

*/

int main(){
    #ifndef ONLINE_JUDGE
    freopen("Input.txt", "r", stdin);
    #endif

    int NumGroups;
    std::cin >> NumGroups;

    int NumGroupsBySize[3] {0, 0, 0};
    int NumTaxis = 0;

    for(int i = 0; i < NumGroups; i++){
        int GroupSize;
        std::cin >> GroupSize;

        if(GroupSize == 4) {
            NumTaxis++;

        } else if (GroupSize == 3){

            if(NumGroupsBySize[0]){
                NumTaxis++;
                NumGroupsBySize[0]--;
            } else {
                NumGroupsBySize[2]++;
            }

        } else if (GroupSize == 2){

            if(NumGroupsBySize[1]){
                NumTaxis++; // combine 2 with 2
                NumGroupsBySize[1] = 0;
            } else{
                NumGroupsBySize[1] = 1;
            }

        } else /*if (GroupSize == 1)*/ {

            if(NumGroupsBySize[2]) {
                NumGroupsBySize[2]--;
                NumTaxis++;
            } else {
                NumGroupsBySize[0]++;
            }

        }
    }

    NumTaxis += NumGroupsBySize[2];
    if(NumGroupsBySize[0]){
        NumTaxis += NumGroupsBySize[0] / 4;
        NumGroupsBySize[0] %= 4;
    }

    int Remaining = NumGroupsBySize[0] + 2 * NumGroupsBySize[1];
    if(Remaining > 4) {
        NumTaxis += 2;
    } else if(Remaining < 5 && Remaining) {
        NumTaxis++;
    }

    std::cout << NumTaxis << '\n';



    return 0;
}