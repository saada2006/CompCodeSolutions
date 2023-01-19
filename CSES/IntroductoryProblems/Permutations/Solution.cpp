#include <iostream>
#include <sstream>
#include <ios>

char* Print2Inc(const int Base, int N, char* Buffer) {
    for(int i = Base; i <= N; i += 2) {
        char Temp[7];
        sprintf(Temp, "%d", i);
        char* Iter = Temp;
        for(;*Iter;Iter++){
            *Buffer = *Iter;
            Buffer++;
        }
        *(Buffer++) = ' ';
    }

    return Buffer;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    const std::size_t BufferSize = 70000000;
    char* Buffer = new char[BufferSize];
    Buffer[0] = '\0';

    int n;
    std::cin >> n;

    if (n == 1){
        std::cout << "1 \n";
        return 0;
    } else if(n < 4) {
        std::cout << "NO SOLUTION\n";
        return 0;
    }

    char* EndBuffer = Print2Inc(1, n, Print2Inc(2, n, Buffer));

    *(EndBuffer++) = '\n';
    *(EndBuffer++) = '\0';

    std::cout << Buffer;
    std::cout.flush();

    delete[] Buffer;

    return 0;
}

/*
    int MaxEven, MaxOdd;

    if(n % 2 == 1) { // n % 2
        MaxEven = n - 1;
        MaxOdd = n;
    } else {
        MaxEven = n;
        MaxOdd = n - 1;
    }
*/