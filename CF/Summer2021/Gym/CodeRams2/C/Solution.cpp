#include <iostream>
#include <utility>
#include <vector>
#include <set>

struct Vertex {
    int Index;
    bool Type; // false - not leaf, true - leaf
    int LeafConnections;
    int RegularConnections;
    int TotalConnections;

    Vertex(const int i) : Index(i) {}

    bool operator<(const Vertex& Other) {
        return this->Index < Other.Index;
    }

    bool operator==(const Vertex& Other) {
        return this->Index == Other.Index;
    }
};

int main() {
    int n;
    std::cin >> n;

    std::set<Vertex> Tree;
    for(int i = 0; i < n; i++) {
        Tree.emplace(i);
    }

    for(int i = 1; i < n; i++) {
        int V0, V1;
        std::cin >> V0 >> V1;
        Vertex V0F(V0);
        auto Iter = Tree.find(Vertex(V0));
        Iter->TotalConnections++;
    }
}