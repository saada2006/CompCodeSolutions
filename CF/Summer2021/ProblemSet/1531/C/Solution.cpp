#include <iostream>
#include <fstream>

int main() {
    #ifndef ONLINE_JUDGE
    std::ifstream InputFile("Input.txt");
    std::cin.rdbuf(InputFile.rdbuf());
    #endif

    int N;
    std::cin >> N;

    char* Grid;
    int GridLength = 0;


    while(N) {
        Grid = new char[++GridLength];

        

        delete[] Grid;
    }
}