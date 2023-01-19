#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

void CreateFrequencyTable(const std::string& Word, int* FrequencyTable) {
    for(const char Letter : Word) {
        FrequencyTable[Letter - 'a']++;
    }
}

int main() {
    freopen("blocks.in", "r", stdin);
    freopen("blocks.out", "w", stdout);

    int NumWordBlocks;
    std::cin >> NumWordBlocks;

    int CompleteLetterFrequencyTable[26], WordFrequencyTable[2][26];
    
    std::fill_n(CompleteLetterFrequencyTable, 26, 0);
    for(int Block = 0; Block < NumWordBlocks; Block++) {
        std::fill_n(WordFrequencyTable[0], 26, 0);
        std::fill_n(WordFrequencyTable[1], 26, 0);

        std::string Word[2];
        std::cin >> Word[0] >> Word[1];

        CreateFrequencyTable(Word[0], WordFrequencyTable[0]);
        CreateFrequencyTable(Word[1], WordFrequencyTable[1]);

        for(int LetterIdx = 0; LetterIdx < 26; LetterIdx++) {
            CompleteLetterFrequencyTable[LetterIdx] += std::max(WordFrequencyTable[0][LetterIdx], WordFrequencyTable[1][LetterIdx]);
        }
    }

    for(int LetterIdx = 0; LetterIdx < 26; LetterIdx++) {
        std::cout << CompleteLetterFrequencyTable[LetterIdx] << '\n';
    }

    return 0;
}
