#include <iostream>
#include <vector>

int main() {
    int t;
    std::cin >> t;

    for(int i = 0; i < t; i++) {
        int n;
        std::cin >> n;

        std::vector<int> Data(n);
        for(int& x : Data) {
            std::cin >> x;
        }

        int NormalNumber;
        if(Data[0] != Data[1]) {
            if(Data[1] != Data[2]) {
                NormalNumber = Data[0];
            } else {
                NormalNumber = Data[1];
            }
        } else {
            NormalNumber = Data[0];
        }

        for(int j = 0; j < n; j++) {
            if(NormalNumber != Data[j]) {
                std::cout << j + 1<< '\n';
                break;
            }
        }
    }

    return 0;
}