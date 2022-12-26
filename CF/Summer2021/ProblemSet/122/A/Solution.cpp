#include <iostream>
#include <string>

bool CheckAlmostLucky(int val, int div) {
    if(div > val) {
        return false;
    } else {
        if(val % div == 0) {
            return true;
        } else {
            int div10 = div * 10;
            int div4 = div10 + 4;
            int div7 = div10 + 7;
            return CheckAlmostLucky(val, div4) || CheckAlmostLucky(val, div7);
        }
    }
}

int main() {
    std::string NumberStr;
    std::cin >> NumberStr;

    bool Lucky = true;
    for(const char c : NumberStr) {
        if(c != '4' && c != '7') {
            Lucky = false;
            break;
        }
    }

    int Number = std::stoi(NumberStr);
    if(Lucky || CheckAlmostLucky(Number, 4) || CheckAlmostLucky(Number, 7)) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }

    return 0;
}