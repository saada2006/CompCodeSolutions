#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::string s;
    int n;
    std::cin >> n >> s;
    // n = s.length();

    int reversals = 0;

    int notOnEven = 0, onEven = 0;
    int previousNotOnEven = 0, previousOnEven = 0;
    for(int i = 0; i < n; i+=2) {
        if(s.at(i) == 'G')
            notOnEven++;
        if(s.at(i+1) == 'G')
            onEven++;

        int currentGain = notOnEven - onEven; // if we switch this prefix, how many more Gs will be on even
        int previousGain = previousNotOnEven - previousOnEven;

        if(currentGain >= 0 && currentGain < previousGain){ // Very important to make sure it is non negative 
            // It is best to reversel this prefix and move on
            std::reverse(s.begin(), s.begin() + i - 2);

            // These constitute our new values for the previous
            // int switchedOnEven = previousNotOnEven;
            // int switchedNotOnEven = previousOnEven;

            // We need to add how much was gained in the non-switched part
            // notOnEven = switchedNotOnEven + notOnEven - previousNotOnEven;
            // onEven = switchedOnEven + onEven - previousOnEven;

            // Now we need to update the current values accoridnly 

            reversals++;

            i = -2;

            notOnEven = onEven = 0;
            
        } else if (currentGain > 0 && i + 2 >= n) {
            reversals++;
        }

        previousNotOnEven = notOnEven;
        previousOnEven = onEven;
    }

    std::cout << reversals << std::endl;

    return 0;
}