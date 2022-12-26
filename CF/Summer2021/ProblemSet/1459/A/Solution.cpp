#include <iostream>
#include <string>

int main() {
    int t;
    std::cin >> t;

    for(int it = 0; it < t; it++) {
        int n;
        std::cin >> n;
        std::cin.ignore();
        std::string Red, Blue;
        Red.reserve(n);
        Blue.reserve(n);
        std::getline(std::cin, Red);
        std::getline(std::cin, Blue);
        
        int NumCardsFavoredR = 0, NumCardsFavoredB = 0;
        for(int i = 0; i < n; i++) {
            char NumR = Red[i];
            char NumB = Blue[i];
            // Note: number chars are in increasing order, no need to parse them as int
            if(NumR > NumB) {
                NumCardsFavoredR++;
            } else if(NumB > NumR) {
                NumCardsFavoredB++;
            }
            // Otherwise this card doesn't matter
        }

        if(NumCardsFavoredR > NumCardsFavoredB) {
            std::cout << "RED\n";
        } else if(NumCardsFavoredB > NumCardsFavoredR) {
            std::cout << "BLUE\n";
        } else {
            std::cout << "EQUAL\n";
        }
    }

    return 0;
}