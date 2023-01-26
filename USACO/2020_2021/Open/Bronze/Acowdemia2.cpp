#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// I am the most laziest person in the world
// I will 100% brute force this
// fight me

int main() {
    
    int k, n;
    cin >> k >>  n;

    vector<string> names(n);
    for(auto& s : names) {
        cin >> s;
    }

    vector<vector<string>> publications(k);
    for(auto& pub : publications) {
        pub.resize(n);
        //cout << "test\n";
        for(auto& s : pub) {
            //cout << "start\n";
            cin >> s;
            //cout << s << '\n';

        }
    }

    // too lazy to cache results
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j) {
                cout << 'B';
                //cout << std::endl;
                continue;
            }


            // find one pub containing seniority
            char comp = '?';
            for(auto& pub : publications) {
                //cout << i << ' ' << j << endl;
                auto iloc = find(pub.begin(), pub.end(), names[i]);
                auto jloc = find(pub.begin(), pub.end(), names[j]);


                //cout << distance(pub.begin(), iloc) << ' ' << distance(pub.begin(), jloc) << std::endl;

                // determine that it is not alphabetical   
                bool alphabetical = true;
                for(auto k = min(iloc, jloc); k != max(iloc, jloc); k++) {
                    auto l = k + 1;
                    //cout << distance(pub.begin(), k) << std::endl;
                    //cout << *k << std::endl;
                    //cout << *l << std::endl;
                    if(*l < *k) {
                        alphabetical = false;
                        break;
                    }
                }

                if(!alphabetical) {
                    comp = (iloc < jloc ? '0' : '1');
                    break;
                }
            }

            cout << comp;
            //cout << "\nEnd" << std::endl;
        }

        cout << '\n';
    }


}

