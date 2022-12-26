#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

int main() {
    freopen("cbarn.in", "r", stdin);
    freopen("cbarn.out", "w", stdout);

    int NumRooms;
    std::cin >> NumRooms;

    std::vector<int> Rooms(NumRooms);
    int RoomDistanceSum = 0;
    int RoomSum = 0;

    for(int i = 0; i < NumRooms; i++) {
        int CurrentRoom;
        std::cin >> CurrentRoom;
        RoomDistanceSum += i * CurrentRoom;
        RoomSum += CurrentRoom;
        Rooms[i] = CurrentRoom;
    }

    int MinDist = RoomDistanceSum;
    int MaxDist = NumRooms - 1;
    for(int i = 0; i < NumRooms; i++) {
        RoomSum -= Rooms[i];
        RoomDistanceSum -= RoomSum;
        RoomDistanceSum += Rooms[i] * MaxDist;
        MinDist = std::min(MinDist, RoomDistanceSum);
        RoomSum += Rooms[i];
    }

    std::cout << MinDist;

    return 0;
}
