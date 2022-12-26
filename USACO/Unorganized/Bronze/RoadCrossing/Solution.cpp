// Copy paste for fast USACO file I/O redirection
#include <iostream>
#include <cstdio>
void InitIO(const char* FileName) {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    
    constexpr std::size_t BufferSize = 256;
    char StrBuf[BufferSize];

    StrBuf[0] = '\0';
    std::snprintf(StrBuf, BufferSize, "%s.in", FileName);
    std::freopen(StrBuf, "r", stdin);

    StrBuf[0] = '\0';
    std::snprintf(StrBuf, BufferSize, "%s.out", FileName);
    std::freopen(StrBuf, "w", stdout);    
}

#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <cctype>

int main() {
    InitIO("circlecross");

    std::string CrossingPoints;
    std::cin >> CrossingPoints;

    // Mark entry points as lower case characters
    std::set<char> EntryPoints;
    for(char& c : CrossingPoints) {
        if(EntryPoints.count(c) == 0) {
            EntryPoints.emplace(c);
            c = std::tolower(c);
        }
    }

    /*
    We iterate through the string in search of lower case characters, which mark entry points
    Then we iterate through the string in a nested loop for search of the exit point, which is the uppercase character
    In this nested loop, we record every entry point to mark a possibly crossing cow in a vector
    We also record exit points to remove the uncrossing cows from the vector
    Once we find the exit point, we tally up the number of cows that between the entry and exit point, were seen entering but not exiting
    */

   int CrossingPairs = 0;
   for(int EntryIdx = 0; EntryIdx < CrossingPoints.length(); EntryIdx++) {
        char EntryPoint = CrossingPoints[EntryIdx];
        if(std::isupper(EntryPoint)) {
            // We don't want to start at an exit point
            continue;
        }

        char ExitPoint = std::toupper(EntryPoint);
        std::set<char> CrossingCows;
        for(int ExitIdx = EntryIdx + 1; ExitIdx < CrossingPoints.length(); ExitIdx++) {
            char CurrentPoint = CrossingPoints[ExitIdx];
            // Have we found the exit yet?
            if(CurrentPoint == ExitPoint) {
                break;
            }

            // Is it an exit point?
            if(std::isupper(CurrentPoint)) {
                // Remove it from crossing cows if it's here
                CrossingCows.erase(CurrentPoint);
            } else {
                // It's an entry point, add it to the set
                CrossingCows.insert(std::toupper(CurrentPoint));
            }
        }

        CrossingPairs += CrossingCows.size();
    }

    std::cout << CrossingPairs << '\n';

    return 0;
}