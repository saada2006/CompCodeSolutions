#include <iostream>
#include <fstream>

void DivideBills(int& Money, int& NumBills, int BillValue){
    NumBills += Money / BillValue;
    Money %= BillValue;
}

int main () {
    #ifndef ONLINE_JUDGE
    std::ifstream InputFile("Input.txt");
    std::cin.rdbuf(InputFile.rdbuf());
    #endif


    int Money;
    std::cin >> Money;

    int NumBills = 0;
    DivideBills(Money, NumBills, 100);
    DivideBills(Money, NumBills, 20);
    DivideBills(Money, NumBills, 10);
    DivideBills(Money, NumBills, 5);
    DivideBills(Money, NumBills, 1);

    std::cout << NumBills << std::endl;
}