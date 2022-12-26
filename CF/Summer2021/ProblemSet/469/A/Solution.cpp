#include <iostream>
#include <set>

int main() {
    int n, p, q;
    std::cin >> n >> p;

    std::set<int> l;
    for(int i = 0; i < p; i++) {
        int x;
        std::cin >> x;
        l.insert(x);
    }
    std::cin >> q;
    for(int i = 0; i < q; i++) {
        int x;
        std::cin >> x;
        l.insert(x);
    }
    if(l.size() == n) {
        std::cout << "I become the guy.\n";
    } else {
        std::cout << "Oh, my keyboard!\n";
    }
}