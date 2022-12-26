#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

/*
Pruning strategy: 
- Check if in bounds
- Check if x == 0 and y == 0
    = Check if step counter is 48 to increment, then return
- Check if we are on a square that hasn't been taken yet
- Check if we are not in a position that requires us to take move in only left or right
*/

// Convert x and y to an index so we can mark squares that have been already covered
int xytoidx(int x, int y) {
    x = 6 - x;
    y = 6 - y;
    return 7 * y + x;
}

// Check if x is outside bounds
bool CheckBounds(int x) {
    return (x < 0 || x > 6); 
}

// Check if x and y are out of bounds
bool CheckBounds(int x, int y) {
    return CheckBounds(x) || CheckBounds(y);
}

// Check if the square at x and y has already been taken
bool CheckSquare(int x, int y, const std::vector<bool>& Marker) {
    return Marker.at(xytoidx(x, y));   
}

// Check if the square at x and y is either outside the square or has been taken
bool CheckValid(int x, int y, const std::vector<bool>& Marker) {
    return CheckBounds(x, y) || CheckSquare(x, y, Marker);
}

// Check if we can't go in front but we can go left or right
bool Possible20Paths(const std::vector<bool>& Marker, int x0, int y0, int x1, int y1, int x2, int y2) {
    if(CheckValid(x2, y2, Marker)) {
        // We can't go front, if xor (x0 y0) (x1, y1) works then our path still works becasuse xor means only a single possible direction to continue int
        if(CheckValid(x0, y0, Marker) ^ CheckValid(x1, y1, Marker)) {
            // We can continue our search since we have only 1 option
            return false;
        } else {
            // Either both paths were valid or invalid, meaning we can no longer continue this search tree and expect a possible path that satisfies the conditions
            return true;
        }
    }
    // We can still go forward, so this search tree is still valid
    return false;
}

void Search(int& Counter, int StepCounter, const char* Constraint, std::vector<bool>& Marker, int x, int y, char Previous) {
    // Are we at the target square yet?
    if(x == 0 && y == 0) {
        // Have we made enough steps yet?
        if(StepCounter == 48) {
            // std::cout << "Yes\n";
            Counter++;
        }
        // Return to terminate this search tree
        return;
    } 
    // Check if our search tree is invalid at this square
    if(StepCounter == 48 || CheckValid(x, y, Marker)) {
        return;
    }

    int NextStep = StepCounter + 1;
    if(Constraint[StepCounter] == 'R') {
        if(Previous == 'L' || Possible20Paths(Marker, x + 1, y - 1, x + 1, y + 1, x + 2, y)) {
            return;
        }
        Marker[xytoidx(x, y)] = true;
        Search(Counter, NextStep, Constraint, Marker, x + 1, y, 'R');
    } else if (Constraint[StepCounter] == 'L') {
        if(Previous == 'R' || Possible20Paths(Marker, x - 1, y - 1, x - 1, y + 1, x - 2, y)) {
            return;
        }
        Marker[xytoidx(x, y)] = true;
        Search(Counter, NextStep, Constraint, Marker, x - 1, y, 'L');
    } else if (Constraint[StepCounter] == 'U') {
        if(Previous == 'D' || Possible20Paths(Marker, x - 1, y + 1, x + 1, y + 1, x, y + 2)) {
            return;
        }
        Marker[xytoidx(x, y)] = true;
        Search(Counter, NextStep, Constraint, Marker, x, y + 1, 'U');
    } else if (Constraint[StepCounter] == 'D') {
        if(Previous == 'U' || Possible20Paths(Marker, x - 1, y - 1, x + 1, y - 1, x, y - 2)) {
            return;
        }
        Marker[xytoidx(x, y)] = true;
        Search(Counter, NextStep, Constraint, Marker, x, y - 1, 'D');
    } else {
        Marker[xytoidx(x, y)] = true;
        if(Previous != 'L' && !Possible20Paths(Marker, x + 1, y - 1, x + 1, y + 1, x + 2, y)) Search(Counter, NextStep, Constraint, Marker, x + 1, y, 'R');
        if(Previous != 'R' && !Possible20Paths(Marker, x - 1, y - 1, x - 1, y + 1, x - 2, y)) Search(Counter, NextStep, Constraint, Marker, x - 1, y, 'L');
        if(Previous != 'D' && !Possible20Paths(Marker, x - 1, y + 1, x + 1, y + 1, x, y + 2)) Search(Counter, NextStep, Constraint, Marker, x, y + 1, 'U');
        if(Previous != 'U' && !Possible20Paths(Marker, x - 1, y - 1, x + 1, y - 1, x, y - 2)) Search(Counter, NextStep, Constraint, Marker, x, y - 1, 'D');
    }

    Marker[xytoidx(x, y)] = false;
}

int main() {
    std::string Path;
    std::cin >> Path;

    // Array of squares so we know which ones are taken and which ones are not
    std::vector<bool> Grid(49); 
    std::fill_n(Grid.begin(), 49, false);

    // Use stack memory instead of heap for faster access 
    char StackMemory[50];
    std::strcpy(StackMemory, Path.c_str());

    // DFS
    int Answer = 0;
    Search(Answer, 0, StackMemory, Grid, 0, 6, 'D');
    std::cout << Answer << '\n';

    return 0;
}