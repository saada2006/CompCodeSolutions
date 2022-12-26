#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::string S;
    std::cin >> S;

    char PreviousChar = '\0';
    int CurrentStreak = 1;
    int Answer = 0;

    for(const char C : S){
        if(C == PreviousChar){
            CurrentStreak++;
        } else {
            CurrentStreak = 1;
            PreviousChar = C;
        }
        Answer = std::max(Answer, CurrentStreak);
    }

    std::cout << Answer << '\n';
    return 0;

}