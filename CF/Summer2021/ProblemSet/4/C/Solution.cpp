#include <iostream>
#include <map>
#include <string>

int main() {
    int n;
    std::cin >> n;

    std::map<std::string, int> Usernames;
    std::string Request;
    Request.reserve(4096);
    for(int i = 0; i < n; i++) {
        std::cin >> Request;
        int* Frequency = &Usernames[Request];
        if(*Frequency == 0) {
            *Frequency = 1;
            std::cout << "OK\n";
        } else {
            std::cout << Request << *Frequency << '\n';
            (*Frequency)++;
        }
        Request.clear();
    }

    return 0;
}