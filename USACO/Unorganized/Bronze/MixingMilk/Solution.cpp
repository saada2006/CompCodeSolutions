#include <iostream>
#include <utility>
#include <cstdio>

void PourMilk(std::pair<int, int>& from, std::pair<int, int>& to) {
    to.second += from.second;
    int back = to.second - to.first;
    if(back >= 0) {
        to.second = to.first;
        from.second = back;
    } else {
        from.second = 0;
    }
}

int main() {
    freopen("mixmilk.in", "r", stdin);
    freopen("mixmilk.out", "w", stdout);

    std::pair<int, int> Buckets[3];

    for(int i = 0; i < 3; i++) {
        std::cin >> Buckets[i].first >> Buckets[i].second;  
    }

    int PrevBucket = 0, NextBucket = 1;

    for(int i = 0; i < 100; i++) {
        PourMilk(Buckets[PrevBucket], Buckets[NextBucket]);

        PrevBucket++;
        NextBucket++;

        PrevBucket %= 3;
        NextBucket %= 3;
    }

    std::cout << Buckets[0].second << '\n';
    std::cout << Buckets[1].second << '\n';
    std::cout << Buckets[2].second << '\n';

    return 0;
}