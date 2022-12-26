#include <iostream>
#include <vector>

std::string s;
std::string stack;

bool grid[7][7] = {false};
int search(int x, int y) {
    if(x < 0 || x > 6 || y < 0 || y > 6 || grid[x][y]) {
        return 0;
    } else if(stack.size() == 48 ) {
        if(x == 0 && y == 6) {
            return 1;
        } else {
            return 0;
        }
    }

    grid[x][y] = true;
    int paths = 0;

    if(s[stack.size()] == '?') {
        stack.push_back('R');
        paths += search(x + 1, y);
        stack.pop_back();

        stack.push_back('L');
        paths += search(x - 1, y);
        stack.pop_back();

        stack.push_back('U');
        paths += search(x, y + 1);
        stack.pop_back();

        stack.push_back('D');
        paths += search(x + 1, y - 1);
        stack.pop_back();
    } else {
        switch(s[stack.size()]) {
            case 'R':
                stack.push_back('R');
                paths += search(x + 1, y);
                stack.pop_back();
                break;
            case 'L':
                stack.push_back('L');
                paths += search(x - 1, y);
                stack.pop_back();
                break;
            case 'U':
                stack.push_back('R');
                paths += search(x + 1, y);
                stack.pop_back();
                break;
            case 'D':
                stack.push_back('D');
                paths += search(x + 1, y - 1);
                stack.pop_back();
                break;
        }
    }

    grid[x][y] = false;
    return paths;
}

int main() {
    std::cin >> s;
    std::cout << search(0, 0);
}