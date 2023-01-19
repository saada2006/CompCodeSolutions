#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

struct Team {
    char Letters[2] { '\0', '\0'};
};

bool CheckTeam(char Player0, char Player10, char Player11) {
    bool Player0Unique0 = Player0 != Player10;
    bool Player0Unique1 = Player0 != Player11;
    bool Player1Same = Player10 == Player11;
    return Player0Unique0 && Player0Unique1 && Player1Same;
}

void InsertTeam(char Player0, char Player1, std::vector<Team>& TeamWinners) {
    if(Player0 > Player1) {
        std::swap(Player0, Player1);
    }

    Team TentativeTeam;
    TentativeTeam.Letters[0] = Player0;
    TentativeTeam.Letters[1] = Player1;

    auto Compare = [TentativeTeam](Team& T0) -> bool {
        return T0.Letters[0] == TentativeTeam.Letters[0] && T0.Letters[1] == TentativeTeam.Letters[1];
    };

    if(std::find_if(TeamWinners.begin(), TeamWinners.end(), Compare) == TeamWinners.end()) {
        TeamWinners.push_back(TentativeTeam);
    }
}

void FindWinners(char a, char b, char c, std::vector<char>& SoloWinners, std::vector<Team>& TeamWinners) {
    // Conditions:
    // Solo winner: a == b && b == c
    // Team a / bc: CheckTeam(a, b, c)
    // Team b / ac: CheckTeam(b, a, c)
    // Team c / ab: CheckTeam(c, a, b)
    // Make sure to sort team letters by lexographic order
    if(a == b && b == c) {
        if(std::find(SoloWinners.begin(), SoloWinners.end(), a) == SoloWinners.end()) {
            SoloWinners.push_back(a);
        }
    } else if(CheckTeam(a, b, c)) {
        InsertTeam(a, b, TeamWinners);
    } else if(CheckTeam(b, a, c)) {
        InsertTeam(b, a, TeamWinners);
    } else if(CheckTeam(c, a, b)) {
        InsertTeam(c, a, TeamWinners);
    } 
}

int main() {
    freopen("tttt.in", "r", stdin);
    freopen("tttt.out", "w", stdout);

    std::string Board[3];
    std::cin >> Board[0] >> Board[1] >> Board[2];

    std::vector<char> SoloWinners;
    std::vector<Team> TeamWinners;

    for(int i = 0; i < 3; i++) {
        FindWinners(Board[i][0], Board[i][1], Board[i][2], SoloWinners, TeamWinners);
        FindWinners(Board[0][i], Board[1][i], Board[2][i], SoloWinners, TeamWinners);
    } 

    FindWinners(Board[0][0], Board[1][1], Board[2][2], SoloWinners, TeamWinners);
    FindWinners(Board[2][0], Board[1][1], Board[0][2], SoloWinners, TeamWinners);
    
    std::cout << SoloWinners.size() << '\n';
    std::cout << TeamWinners.size() << '\n';

    return 0;
}