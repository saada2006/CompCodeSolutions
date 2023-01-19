#include <iostream>
#include <string>
#include <set>
#include <unordered_set>

struct Coord {
    int x, y;
    char d;

    bool operator<(const Coord& Other) const {
        if(d != Other.d) {
            return d < Other.d;
        }

        if(x == Other.x) {
            return (y < Other.y);
        } else {
            return (x < Other.x);
        }
    }

    bool operator==(const Coord& Other) const {
        return (x == Other.x && y == Other.y && d == Other.d);
    }
};

void solve() {
    std::string Path;
    std::cin >> Path;

    Coord CurrentPosition;
    CurrentPosition.x = CurrentPosition.y = 0;

    std::set<Coord> VisitedPositions;
    int Seconds = 0;

    for(const char Direction : Path) {
        Coord NextPosition = CurrentPosition;
        NextPosition.d = Direction;
        char Opposite;
        
        switch(Direction) {
            case 'N': {
                NextPosition.y++;
                Opposite = 'S';
            } break;
            case 'S': {
                NextPosition.y--;
                Opposite = 'N';
            } break;
            case 'E': {
                NextPosition.x++;
                Opposite = 'W';
            } break;
            case 'W': {
                NextPosition.x--;
                Opposite = 'E';
            } break;
        }

        Coord Origin = CurrentPosition;
        Origin.d = Opposite;

        if(VisitedPositions.count(NextPosition) == 1 || VisitedPositions.count(Origin) == 1) {
            Seconds++;
        } else {
            Seconds += 5;
            VisitedPositions.insert(NextPosition);
            VisitedPositions.insert(Origin);
        }

        CurrentPosition = NextPosition;
    }

    std::cout << Seconds << '\n';
}

int main() {
    int t;
    std::cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}