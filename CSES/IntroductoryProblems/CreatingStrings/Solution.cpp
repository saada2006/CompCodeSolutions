#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>

int main() {
    std::string s;
    std::cin >> s;

    std::sort(s.begin(), s.end());
    
    int NumPermutations = 0;
    std::ostringstream Output;
    do {
        Output << s << '\n';
        NumPermutations++;
    } while (std::next_permutation(s.begin(), s.end()));

    std::cout << NumPermutations << '\n' << Output.str();

    return 0;
}