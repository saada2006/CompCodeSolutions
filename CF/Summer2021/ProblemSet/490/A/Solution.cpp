#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

int main() {
    int n;
    std::cin >> n;

    std::vector<std::pair<int, int>> Students;
    Students.reserve(n);

    int Frequency[3] {0, 0, 0};
    for(int i = 1; i <= n; i++) {
        int Skill;
        std::cin >> Skill;
        Frequency[Skill - 1]++;
        Students.emplace_back(Skill, i);
    }

    std::sort(Students.begin(), Students.end());

    auto Compare = [](const std::pair<int, int>& student, int skill) -> bool{
        return student.first < skill;
    };

    std::vector<std::pair<int, int>>::iterator Students1 = Students.begin();
    std::vector<std::pair<int, int>>::iterator Students2 = std::lower_bound(Students.begin(), Students.end(), 2, Compare);
    std::vector<std::pair<int, int>>::iterator Students3 = std::lower_bound(Students.begin(), Students.end(), 3, Compare);

    int MaxTeams = std::min(Frequency[0], std::min(Frequency[1], Frequency[2]));
    std::cout << MaxTeams << '\n';

    for(int i = 0; i < MaxTeams; i++) {
        std::cout << Students1->second << ' '
                  << Students2->second << ' '
                  << Students3->second << '\n';

        Students1++;
        Students2++;
        Students3++;
    }

    return 0;
}