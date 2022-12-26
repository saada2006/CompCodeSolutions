#include <iostream>
#include <fstream>
#include <utility>
#include <algorithm>

int main() {
    #ifndef ONLINE_JUDGE
    std::ifstream InputFile("Input.txt");
    std::cin.rdbuf(InputFile.rdbuf());
    #endif

    int N;
    std::cin >> N;

    for(int i = 0; i < N; i++){
        int Skills[4];

        std::cin >> Skills[0] >> Skills[1] >> Skills[2] >> Skills[3];

        int Finalist[2];

        Finalist[0] = std::max(Skills[0], Skills[1]);
        Finalist[1] = std::max(Skills[2], Skills[3]);

        if(Finalist[0] > std::min(Skills[2], Skills[3]) && Finalist[1] > std::min(Skills[0], Skills[1])){
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
}