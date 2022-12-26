#include <iostream>
#include <string>

std::string FindWinner(std::string& Game) {
    int PlayerMoney[2] {0, 0}; // Alice - 0, Bob - 1
    
    int ZeroChars = 0;
    bool MidChar = false;

    // Since Alice is going first, she can wait until Bob has turned the string into a palindrome
    // Solution for how much this will cost Bob: count "different" characters

    // Scope to avoid pollution of variables into function scope
    {
        auto FirstPartIter = Game.begin();
        auto SecondPartIter = Game.end() - 1;
        while(SecondPartIter > FirstPartIter) {
            if(*FirstPartIter != *SecondPartIter) {
                std::cout << "Zero pair\n";
                PlayerMoney[1]++;
                *FirstPartIter = '1'; 
                *SecondPartIter = '1';
            }
            if(*FirstPartIter == '0') {
                ZeroChars ++;
            }
            FirstPartIter++;
            SecondPartIter--;
        }

        // Mid char
        if(Game.length() % 2 == 0 && *FirstPartIter == '0') {
            MidChar = true;
        }

    }

    // Now that it's a palindrome, Alice must select a char to change
    // Then Bob can pass
    // Alice must choose a second letter to convert as well
    // Then after that Bob can't pass again, he has to change 2 letters 
    // We can calculate for Alice as ZeroChar / 2 since she spends 2 dollars for every 4 zeros
    // For Bob we subtract 2 from ZeroChar first to represent Alice "going first"

    std::cout << "Zer: " << ZeroChars * 2 << '\n';

    PlayerMoney[0] += 2 * (ZeroChars % 2) + ZeroChars;
    PlayerMoney[1] += ZeroChars;
    
    

    if(MidChar) {
        if(ZeroChars % 2 == 1) {
            PlayerMoney[0]++;
        } else {
            PlayerMoney[1]++;
        }
    }

std::cout << PlayerMoney[0] << ' ' << PlayerMoney[1] << '\n';

    if(PlayerMoney[0] == PlayerMoney[1]) {
        return "DRAW";
    } else if (PlayerMoney[0] > PlayerMoney[1]) {
        return "BOB";
    } else {
        return "ALICE";
    }
}

int main () {
    int t;
    std::cin >> t;

    for(int i = 0; i < t; i++) {
        int n;
        std::cin >> n;
        std::cin.ignore();
        std::string Game;
        Game.reserve(n);
        std::getline(std::cin, Game);
        std::cout << FindWinner(Game) << '\n';
    }

    return 0;
}