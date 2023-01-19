#include <iostream>
#include <string>

int main() {
    std::string s;
    std::getline(std::cin, s);
    const std::string Hello = "hello";

    auto SIter = s.begin();
    int FoundChars = 0;

    for(const char c : Hello) {
        while(SIter != s.end()) {
            char sc = *SIter;
            SIter++;
            if(sc == c) {
                FoundChars++;
                break;
            }
        }
    }  
    
    std::cout << (FoundChars == Hello.length() ? "YES" : "NO");
}