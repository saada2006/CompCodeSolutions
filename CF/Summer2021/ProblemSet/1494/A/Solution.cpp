#include <iostream>
#include <string>

int main () {
    int t;
    std::cin >> t;
    std::cin.ignore();

    for(int i = 0; i < t; i++) {
        std::string ABC;
        std::getline(std::cin, ABC);

        char Start = ABC.front();
        char End = ABC.back();

        if(Start == End) {
            std::cout << "NO\n";
            continue;
        }

        int Counter[2] {0, 0};
        bool Valid[2] {true, true};

        for(const char C : ABC) {
            if(C == Start) {
                Counter[0]++;
                Counter[1]++;
            } else if (C == End) {
                Counter[0]--;
                Counter[1]--;
            } else {
                Counter[0]++;
                Counter[1]--;
            }

            if(Counter[0] < 0) {
                Valid[0] = false;
            }
            if(Counter[1] < 0) {
                Valid[1] = false;
            }
        }

        if(Counter[0] != 0) {
                Valid[0] = false;
        }

        if(Counter[1] != 0) {
            Valid[1] = false;
        }

        if(Valid[0] || Valid[1]) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }

    }

    return 0;
}