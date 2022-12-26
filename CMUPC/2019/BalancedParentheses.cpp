#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define PAREN 0
#define BRACE 1
#define BRACK 2

#define CHECK_TOP(v) {if(layers.empty() || layers.back() != v) {cout << "Not Balanced\n"; return;} else {layers.pop_back();}}

void solve() {
    string s;
    cin >> s;

    vector<int> layers;
    for(char c : s) {
        if(c == '(') {
            layers.push_back(PAREN);
        } else if(c == '{') {
            layers.push_back(BRACE);
        } else if(c == '[') {
            layers.push_back(BRACK);
        } else if(c == ')') {
            CHECK_TOP(PAREN);
        } else if(c == '}') {
            CHECK_TOP(BRACE);
        } else if(c == ']') {
            CHECK_TOP(BRACK);
        }
    }

    cout << (layers.empty() ? "Balanced" : "Not Balanced") << '\n';
}

int main() {
    int t;
    cin >> t;

    while(t--) solve();
}
