#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>
#include <cmath>

int main() {
    int n, s;
    std::cin >> n >> s;

    std::vector<int> Input;
    Input.reserve(n + 1);
    Input.resize(n);
    for(int& x: Input) {
        std::cin >> x;
    }

    if(n == 1) {
        std::cout << std::abs(Input.front() - s);
    }

    std::sort(Input.begin(), Input.end());

    int MedianPos = Input.size() / 2;
    int OriginalMedian = Input.at(MedianPos);

    std::uint64_t Operations = 0;

    if(OriginalMedian < s) {
        for(auto Iter = Input.begin() + MedianPos; Iter != Input.end(); Iter++) {
            if(*Iter >= s) {
                break;
            } else {
                Operations += s - *Iter;
            }
        }
    } else if (OriginalMedian > s) {
        std::reverse(Input.begin(), Input.end());

        for(auto Iter = Input.begin() + MedianPos; Iter != Input.end(); Iter++) {
            if(*Iter <= s) {
                break;
            } else {
                Operations += *Iter - s;
            }
        }
    }

    std::cout << Operations;

    return 0;
}