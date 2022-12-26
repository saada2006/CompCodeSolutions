#include <iostream>
#include <string>
#include <map>

int main() {
    int n;
    std::cin >> n;
    int faces = 0;
    std::map<std::string, int> Shapes {
        {"Tetrahedron", 4},
        {"Cube", 6},
        {"Octahedron", 8},
        {"Dodecahedron", 12},
        {"Icosahedron", 20},
    };
    for(int i = 0; i < n; i++) {
        std::string s;
        std::cin >> s;
        faces += Shapes[s];
    }
    std::cout << faces << '\n';
    return 0;
}