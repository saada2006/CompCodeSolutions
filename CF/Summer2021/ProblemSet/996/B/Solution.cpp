#include <iostream>
#include <fstream>

int main () {
    #ifndef ONLINE_JUDGE
    std::ifstream InputFile("Input.txt");
    std::cin.rdbuf(InputFile.rdbuf());
    #endif

    int NumEntrances;
    std::cin >> NumEntrances;

    /*
    We can do it like this: 

    Assuming no other entrance is used, we can see how long it takes for allen to exit through an entrance
    Then we can take the entrance that takes the least amount of time 
    */

    int EntranceUsed = 0;
    int EntranceTime = 2147483647;

    for(int i = 0; i < NumEntrances; i++){
        int NumPeople;
        std::cin >> NumPeople;

        // After NumPeople minutes, where will allen be and how long will it take him to get back to entrance i?
        int AllensCurrentPosition = NumPeople % NumEntrances; 
        int RelativeEntrancePosition = i;
        if(AllensCurrentPosition > i){
            RelativeEntrancePosition += NumEntrances;
        }
        int Distance = RelativeEntrancePosition - AllensCurrentPosition;

        int CurrentEntranceTime = NumPeople + Distance;
        if(CurrentEntranceTime < EntranceTime) {
            EntranceUsed = i;
            EntranceTime = CurrentEntranceTime;
        }
    }

    // Add 1 since entrances are not 0-indexed in solution
    EntranceUsed++;
    std::cout << EntranceUsed << '\n';

    return 0;
}