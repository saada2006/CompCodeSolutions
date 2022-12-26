#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> BestSubseq, CurrentSubseq;
    BestSubseq.reserve(n);
    CurrentSubseq.reserve(n);

    int PreviousInt = -2;
    bool PreviousErase = false;
    bool FirstIter = true;

    for(int i = 0; i < n; i++) {
        int CurrentInt;
        std::cin >> CurrentInt;

        if(CurrentInt == PreviousInt + 1 || FirstIter) {
            CurrentSubseq.push_back(i + 1);
            PreviousErase = FirstIter = false;
            PreviousInt = CurrentInt;
        } else {

            if(!PreviousErase) {
                PreviousErase = true;
            } else {
                if(BestSubseq.size() < CurrentSubseq.size()) {
                    std::copy(CurrentSubseq.begin(), CurrentSubseq.end(), std::back_insert_iterator<std::vector<int>>(BestSubseq));
                }
                CurrentSubseq.clear();
                CurrentSubseq.push_back(i + 1);
                PreviousErase = false;
                PreviousInt = CurrentInt;
            }
        }
    }

    if(BestSubseq.size() < CurrentSubseq.size()) {
        std::copy(CurrentSubseq.begin(), CurrentSubseq.end(), std::back_insert_iterator<std::vector<int>>(BestSubseq));
    }

    std::cout << BestSubseq.size() << '\n';
    for(const int x : BestSubseq) {
        std::cout << x << ' ';
    }
}