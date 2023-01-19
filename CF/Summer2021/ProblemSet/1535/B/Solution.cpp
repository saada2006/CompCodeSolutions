#include <iostream>
#include <fstream>
#include <vector>
#include <numeric>

int main () {
    #ifndef ONLINE_JUDGE
    std::ifstream InputFile("Input.txt");
    std::cin.rdbuf(InputFile.rdbuf());
    #endif
    
    int t;
    std::cin >> t;

    for(int i = 0; i < t; i++) {
        int n;
        std::cin >> n;

        std::vector<int> a(n);
        for(int& ai : a){
            std::cin >> ai;
        }

        
        
    }

}