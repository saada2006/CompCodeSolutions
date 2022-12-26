#include <iostream>

int main() {
    int a, b;
    std::cin >> a >> b;

    int years = 0;
    while(a <= b) {
        years++;
        a *= 3;
        b *= 2;
    }

    std::cout << years;
}

/*
    const double log2 = std::log(2.0);
    const double log3 = std::log(3.0);
    const double diffdiv = log2 - log3;

    double a, b;
    std::cin >> a >> b;

    double t = std::log(a / b) / diffdiv;
    int ti32ciel = 1 + (int)t;

    std::cout << ti32ciel;
*/