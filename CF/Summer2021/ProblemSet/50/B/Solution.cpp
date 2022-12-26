#include <iostream>
#include <fstream>
#include <string>
#include <cstdint>
#include <map>
#include <stdio.h>

int main () {
    #ifndef ONLINE_JUDGE
    freopen("Input.txt", "r", stdin);
    #endif

    std::string S;
    std::getline(std::cin, S);

    std::map<char, uint64_t> FrequencyTable;
    for(const char C : S) {
        auto Iter = FrequencyTable.find(C);
        if(Iter == FrequencyTable.end()){
            FrequencyTable.emplace(C, 1);
        } else {
            Iter->second++;
        }
    }

    uint64_t Answer = 0;
    for(const auto& Element : FrequencyTable){
        Answer += Element.second * Element.second;
    }

    std::cout << Answer << '\n';

    return 0;
}