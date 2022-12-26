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

/*
Idea: make list of possible buckets on each side
For each: what if we take this bucket on this day? 

In reality the number of different bucket sequences matter, not the readings, but that would be complicated to implement 
Basically, if we take a bucket from A to B, we "leave" it there and then try out the all the buckets there

At the end of the days, we can insert the reading into a set

Implementation: day is kept track of with depth value starting from 0 and ending at 4 on saturday so we can record the measurements
We loop through the buckets at the current farm and do a dfs asssuming FJ took these buckets
We erase the bucket from the vector and push it back into the other vector
Once the dfs returns we insert that same bucket back into that positions
*/

#include <vector>
#include <unordered_set>

std::unordered_set<int> PossibleReadings;
std::vector<int> BucketOptions[2];

void Search(int day, int MilkReading) {
    if(day == 4) {
        //std::cout << MilkReading << '\n';
        PossibleReadings.insert(MilkReading);
        return;
    }

    int NextDay = day + 1;
    int BucketSet = day % 2;
    int NextSet = NextDay % 2;

    for(int i = 0; i < BucketOptions[BucketSet].size(); i++) {
        int BucketSize = BucketOptions[BucketSet][i];
        //std::cout << BucketSize << '\n';
        BucketOptions[BucketSet].erase(BucketOptions[BucketSet].begin() + i);
        BucketOptions[NextSet].push_back(-BucketSize);
        //std::cout << MilkReading + BucketSize << '\n';
        Search(NextDay, MilkReading + BucketSize);
        BucketOptions[NextSet].pop_back();
        BucketOptions[BucketSet].insert(BucketOptions[BucketSet].begin() + i, BucketSize);
    }
}

int main() {
    InitIO("backforth");

    BucketOptions[0].reserve(12);
    BucketOptions[1].reserve(12);

    BucketOptions[0].resize(10);
    BucketOptions[1].resize(10);

    for(int& X : BucketOptions[0]) {
        std::cin >> X;
        X = -X;
    }

    for(int& X : BucketOptions[1]) {
        std::cin >> X;
    }

    Search(0, 1000);
    std::cout << PossibleReadings.size() << '\n';

    return 0;
}