#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

struct Coordinate {
    int x, y;
    Coordinate(void) : x(0), y(0) {}

    Coordinate operator+(const Coordinate& Other) const {
        Coordinate TransformedPosition;

        TransformedPosition.x = x + Other.x;
        TransformedPosition.y = y + Other.y;

        return TransformedPosition;
    }

    Coordinate operator-(const Coordinate& Other) const {
        Coordinate TransformedPosition;

        TransformedPosition.x = x - Other.x;
        TransformedPosition.y = y - Other.y;

        return TransformedPosition;
    }
};

constexpr int FieldSideLength = 2 * 1000 + 1;

int GetPos(Coordinate XY) {
    int Pos = XY.y * FieldSideLength + XY.x;
    return Pos;
}

int CheckCell(const std::vector<int>& Field, Coordinate XY) {
    return Field.at(GetPos(XY));
}

void MarkCell(std::vector<int>& Field, Coordinate XY, int T) {
    Field[GetPos(XY)] = T;
}

int main() {
    freopen("mowing.in", "r", stdin);
    freopen("mowing.out", "w", stdout);

    int n;
    std::cin >> n;
    std::cin.ignore();

    Coordinate FJ;
    FJ.x = FJ.y = 1000;

    int DistanceSum = 0;
    std::vector<int> Field(FieldSideLength * FieldSideLength);
    // Initial time: -1
    std::fill(Field.begin(), Field.end(), -1);

    constexpr int DefaultAns = 9999999;
    int Answer = DefaultAns;

    for(int i = 0; i < n; i++) {
        char Direction;
        int Distance;
        std::cin >> Direction >> Distance;
        std::cin.ignore();

        Coordinate Transform;
        if(Direction == 'N') {
            Transform.y = 1;
        } else if (Direction == 'S') {
            Transform.y = -1;
        } else if (Direction == 'E') {
            Transform.x = 1;
        } else {
            Transform.x = -1;
        }

        int EndTime = DistanceSum + Distance;
        for(int Time = DistanceSum + 1; Time <= EndTime; Time++) {
            FJ = FJ + Transform;
            int CellTime = CheckCell(Field, FJ);
            if(CellTime != -1) {
                int RemoweTime = Time - CellTime;
                Answer = std::min(Answer, RemoweTime);
            }
            MarkCell(Field, FJ, Time);
        }

        DistanceSum += Distance;
    }

    if(Answer == DefaultAns) {
        Answer = -1;
    }

    std::cout << Answer << '\n';

    return 0;
}