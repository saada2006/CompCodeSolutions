#include <iostream>
#include <string>
#include <map>

int main() {
    int t;
    std::cin >> t;

    for(int i = 0; i < t; i++) {
        int n;
        std::cin >> n;
        std::string ArrayStr;
        ArrayStr.reserve(n);
        std::cin >> ArrayStr;

        std::map<int, int> EndPoints;
        EndPoints[1]++; // ...what? I d have no idea why I need this to make stuff work unless i=-1 is part of the array -\_ :| _/-
        int Accum = 0;
        for(int j = 0; j < n; j++) {
            Accum += ArrayStr[j] - '0';
            EndPoints[Accum - j]++;
        }

        std::int64_t GoodSubarrays = 0;
        for(const auto& Frequency : EndPoints) {
            std::int64_t Freq064 = Frequency.second;
            std::int64_t Freq164 = Freq064 - 1;
            GoodSubarrays += (Freq064 * Freq164) / 2; 
        }

        std::cout << GoodSubarrays << '\n';
    }

    return 0;
}

/*
        for(int j = 0; j < n; j++) {
            int Subtract = j > 0 ? Array[j - 1] : 0;
            int Offset = 1;
            for(int k = j; k < n; k++, Offset++) {
                int Accum = Array[k] - Subtract;
                if(Accum == Offset) {
                    GoodSubarrays++;
                }
                int Diff = Offset - Accum;
                if(Diff > 0) {
                    int MinIterations = Diff / 9;
                    k += MinIterations;
                    Offset += MinIterations;
                }
            }
        }
*/