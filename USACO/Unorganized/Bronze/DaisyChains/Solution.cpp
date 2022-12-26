#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> Petals(n);
    for(int& x : Petals) {
        std::cin >> x;
    }

    int Answer = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {

            int Sum = 0;
            for(int k = i; k <= j; k++) {
                Sum += Petals[k];
            }

            int Range = j - i + 1;
            if(Sum % Range != 0) {
                continue;
            }
            int Average = Sum / Range;

            for(int k = i; k <= j; k++) {
                if(Petals[k] == Average) {
                    Answer++;
                    break;
                }
            }

        }
    }

    std::cout << Answer << '\n';
    return 0;
}