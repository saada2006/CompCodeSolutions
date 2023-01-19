#include <iostream>
#include <algorithm>

int main() {
    int a, b, c;
    std::cin >> a >> b >> c;

    int m = 0;

    m = std::max(m, a * b * c  );
    m = std::max(m, a + b + c  );
    m = std::max(m, a + b * c  );
    m = std::max(m, a * b + c  );
    m = std::max(m, a * (b + c));
    m = std::max(m, (a + b) * c);

    std::cout << m << '\n';
    return 0;
}