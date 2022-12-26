/*
ID: shadax31
LANG: C++
TASK: crypt1
*/

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <cstdio>
using namespace std;
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

// brute force complete search

bool check_digits(vector<int> digits, int v) {
    string s = to_string(v);
    for(char c : s) {
        int x = c - '0';
        if(!binary_search(digits.begin(), digits.end(), x))
            return false;
    }

    return true;
}

int main() {
    #ifndef ONLINE_JUDGE
    InitIO("crypt1");
    #endif
    int n;
    cin >> n;

    vector<int> digits(n);
    for(int& x : digits)
        cin >> x;
    
    sort(digits.begin(), digits.end());

    int solutions = 0;

    for(int i = 0; i < n; i++) 
        for(int j = 0; j < n; j++)
            for(int k = 0; k < n; k++)
                for(int l = 0; l < n; l++)
                    for(int m = 0; m < n; m++) {
                        int num1 = 100 * digits[i] + 10 * digits[j] + digits[k];
                        
                        int part1 = num1 * digits[l];
                        int part2 = num1 * digits[m];

                        int prod = part1 + 10 * part2;

                        if(to_string(prod).size() == 4 && to_string(part1).size() == 3 && to_string(part2).size() == 3 && check_digits(digits, part1) && check_digits(digits, part2) && check_digits(digits, prod)) {
                            //cout << num1 << ' ' << digits[m] << digits[l] << ' ' << part1 << ' ' << part2 << ' ' << prod << '\n';
                            solutions++;
                        }
                            
                    }
    
    cout << solutions << '\n';
}