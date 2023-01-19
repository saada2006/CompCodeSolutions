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
#include <map>
#include <utility>
#include <algorithm>

int main() {
    InitIO("guess");

    /*
    Brute force approach:
    For each animal, we find another animal with which it shares the most qualities with
    The number of qualities is the longest transcript possible given that the target animal is that animal
    
    To speed things up we can replace string qualities with numbers, ie quality i or quality j
    To do this we can create a <string, int> map and start a counter and i = 0
    */

    std::vector<std::vector<int>> Animals;

    std::map<std::string, int> QualityMappings;
    int NextQuality = 0;

    int NumAnimals;
    std::cin >> NumAnimals;
    Animals.resize(NumAnimals);

    for(std::vector<int>& Qualities : Animals) {
        std::string IgnoreName;
        std::cin >> IgnoreName;

        int NumQualities;
        std::cin >> NumQualities;
        Qualities.resize(NumQualities);

        for(int& Quality : Qualities) {
            std::string QualityName;
            std::cin >> QualityName;

            auto QualityID = QualityMappings.find(QualityName);
            if(QualityID == QualityMappings.end()) {
                QualityMappings.insert(std::make_pair(QualityName, NextQuality));
                Quality = NextQuality;
                NextQuality++;
            } else {
                Quality = QualityID->second;
            }
        }

        // Sort to allow binsearch
        std::sort(Qualities.begin(), Qualities.end());
    }

    int MaxYesAnswer = 0;
    for(int AnimalIdx = 0; AnimalIdx < NumAnimals; AnimalIdx++) {
        auto& FindQualities = Animals[AnimalIdx];
        for(int SearchIdx = 0; SearchIdx < NumAnimals; SearchIdx++) {
            if(SearchIdx == AnimalIdx) {
                continue;
            }

            auto& SearchQualities = Animals[SearchIdx];

            int NumMatchingQualities = 0;
            for(const int Quality : FindQualities) {
                if(std::binary_search(SearchQualities.begin(), SearchQualities.end(), Quality)) {
                    NumMatchingQualities++;
                }
            }
            // We need 1 more "yes" to differentiate the matching animal from our target animal
            MaxYesAnswer = std::max(MaxYesAnswer, NumMatchingQualities + 1);
        }
    }

    std::cout << MaxYesAnswer << '\n';

    return 0;
}