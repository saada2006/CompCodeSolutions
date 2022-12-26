/*
ID: shadax31
LANG: C++
TASK: namenum
*/
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <cstdio>
using namespace std;
void InitIO(const char* FileName) {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    
    constexpr std::size_t BufferSize = 256;
    char StrBuf[BufferSize];

    StrBuf[0] = '\0';
    std::snprintf(StrBuf, BufferSize, "%s.in", FileName);
    std::freopen(StrBuf, "r", stdin);

    StrBuf[0] = '\0';
    std::snprintf(StrBuf, BufferSize, "%s.out", FileName);
    std::freopen(StrBuf, "w", stdout);    
}

char get_touch_tone(int index, int i) {
    if(index < 7) {
        return 3 * (index - 2) + 'A' + i;
    } else if(index == 7) {
        if(i == 0)
            return 'P';
        else
            return 3 * (index - 2) + 'A' + i + 1;
    } else {
        return 3 * (index - 2) + 'A' + i + 1;
    }
}

int main() {
    std::freopen("dict.txt", "r", stdin);

    string s;
    vector<string> dict;
    while(getline(cin, s)) {
        dict.push_back(s);
    }
    sort(dict.begin(), dict.end());

    InitIO("namenum");

    cin >> s;
    
    // use tree traversal to go through all offsets

    vector<int> fake_stack;
    fake_stack.resize(s.length());
    fill(fake_stack.begin(), fake_stack.end(), 0);

    int level = fake_stack.size() - 1;

    bool finished = false;
    bool none = true;
    while(!finished) {
        string name;
        for(int i = 0; i < s.length(); i++) {
            name += get_touch_tone(s[i] - '0', fake_stack[i]);
        }

        if(binary_search(dict.begin(), dict.end(), name)) {
            cout << name << '\n';
            none = false;
        }

        // go up through the levels
        while(true) {
            fake_stack[level]++;
            if(fake_stack[level] == 3) {
                if(level == 0) {
                    finished = true;
                    break;
                } else {
                    fake_stack[level] = 0;
                    level--;
                }
            } else {
                break;
            }
        }
        // reset level
        level = fake_stack.size() - 1;
    }

    if(none)
        cout << "NONE\n";

}