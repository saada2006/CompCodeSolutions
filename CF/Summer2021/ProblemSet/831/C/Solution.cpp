#include <iostream>
#include <vector>
#include <set>

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> Ratings(n);
    for(int& x : Ratings) {
        std::cin >> x;
    }

    std::set<int> InitialValues;
    for(int i = 0; i < k; i++) {
        int CurrentInitial;
        std::cin >> CurrentInitial;
        for(const int Rating : Ratings) {
            CurrentInitial -= Rating;
            InitialValues.insert(CurrentInitial);
        }
    }

    std::cout << InitialValues.size() << '\n';
    for(const int X : InitialValues) {
        std::cout << X << '\n';
    }

    return 0;
}