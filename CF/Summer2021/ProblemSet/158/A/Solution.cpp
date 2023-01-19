#include <iostream>
#include <stdio.h>
#include <vector>

int main(){
    #ifndef ONLINE_JUDGE
    freopen("Input.txt", "r", stdin);
    #endif

    int NumParticipants, Finisher;

    std::cin >> NumParticipants >> Finisher;
    Finisher--;

    std::vector<int> Score(NumParticipants);
    for(int i = 0; i < NumParticipants; i++){
        std::cin >> Score[i];
    }

    int Answer = 0;
    for(int i = 0; i < NumParticipants; i++){
        if(Score[i] < 1){
            continue;
        }
        if(Score[i] >= Score[Finisher]){
            Answer++;
        }
    }

    std::cout << Answer;
    return 0;
}