#include <iostream>
#include <string>
#include <cstdlib>

void CheckName(const std::string& name) {
    const std::string kobus = "kobus";
    if(name.length() >= kobus.length()) {
        return;
    } else {
        for(int idx = 0; idx < name.length(); idx++) {
            if(name[idx] != kobus[idx]) {
                return;
            }
        }
        std::cout << "sem chance";
        std::exit(0);
    }
}

int main() {
    int n;
    std::cin >> n;
    std::cin.ignore();

    for(int i = 0; i < n; i++) {
        std::string s;
        std::getline(std::cin, s);
        CheckName(s);
    }

    std::cout << "kobusacdefghijlmnpqrtvwxyz";
    return 0;
}