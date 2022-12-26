#include <iostream>

int main() {
    int n;
    std::cin >> n;

    int ReqStickFreq[8] = {0, 0, 0, 0, 0, 0, 0, 0};

    for(int i = 0; i < n; i++) {
        char c;
        std::cin >> c;

        if(c == 'c') {
            ReqStickFreq[0]++;
        } else if(c == 'o') {
            ReqStickFreq[1]++;
        } else if(c == 'd') {
            ReqStickFreq[2]++;
        } else if(c == 'e') {
            ReqStickFreq[3]++;
        } else if(c == 'r') {
            ReqStickFreq[4]++;
        } else if(c == 'a') {
            ReqStickFreq[5]++;
        } else if(c == 'm') {
            ReqStickFreq[6]++;
        } else if(c == 's') {
            ReqStickFreq[7]++;
        } 
    }

    int min = 9999999;
    for(int i = 0; i < 8; i++) {
        if(min > ReqStickFreq[i]){
            min = ReqStickFreq[i];
        }
    }

    std::cout << min;
}