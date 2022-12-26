#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>
#include <cstring>

size_t SafeSub(size_t v, size_t s) {
    if(s > v) {
        return 0;
    } else {
        return v - s;
    }
}

int main() {
    freopen("censor.in", "r", stdin);
    freopen("censor.out", "w", stdout);

    std::string Message, Censor;
    std::cin >> Message >> Censor;

    char StackMemory[101];
    std::strcpy(StackMemory, Censor.c_str());

    std::string Solution;
    Solution.reserve(Message.length() + 1);

    for(const char C : Message) {
        Solution.push_back(C);
        size_t Position = Solution.find(StackMemory, SafeSub(Solution.size(), Censor.size()));
        if(Position != std::string::npos) {
            Solution.erase(Position, Censor.length());
        }
    }

    Solution.push_back('\n');
    std::cout << Solution;

    return  0;
}

/*
    size_t Position = 0;
    while(true) {
        if(Censor.length() != 1) {
            Position = Message.find(StackMemory, Position);
        } else {
            Position = Message.find(*StackMemory, Position);
        }

        if(Position == std::string::npos) {
            break;
        }

        size_t Offset = 0;
        size_t Position2 = Position + Censor.length();
        if(Message.find(StackMemory, Position2) == Position2) {
            Offset == Censor.length();
        }

        Message.erase(Position, Censor.length() + Offset);

        // The new erase could have revealed a new subsequence
        // At most this subsequence starts at Position - (Censor.length() - 1) chars back
        // If Position is lequal Censor.length() - 1 set Position to 0
        // Otherwise sub Censor.length() - 1
        if(Position <= Censor.length() - 1) {
            Position = 0;
        } else {
            Position -= Censor.length() - 1;
        }
    }

    std::cout << Message << '\n';
*/