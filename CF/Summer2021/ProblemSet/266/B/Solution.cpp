#include <iostream>
#include <string>

int main() {
    int n, t;
    std::cin >> n >> t;
    std::cin.ignore();
    std::string Queue;
    Queue.reserve(n);
    std::getline(std::cin, Queue);

    for(int x = 0; x < t; x++) {
        for(int i = 0; i + 1 < Queue.size(); i++) {
            if(Queue[i] == 'B') {
                int j = i + 1;
                if(Queue[j] == 'G') {
                    Queue[i] = 'G';
                    Queue[j] = 'B';
                    i++;
                }
            }
        }
    }

    std::cout << Queue;
    return 0;
}