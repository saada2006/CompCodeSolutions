#include <iostream>
#include <vector>

using namespace std;

struct Cow {
    int s;
    int t;
    int c;
};

// stands for air conditioning, not accepted (well hopefully)
struct AC {
    int m;
    int a;
    int b;
    int p;
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<Cow> cows(n);
    for(Cow& c : cows) {
        cin >> c.s >> c.t >> c.c;
        c.s--;
        //c.t--; ending size (0 indexing)
    }
    
    vector<AC> acs(m);
    for(AC& ac : acs) {
        cin >> ac.a >> ac.b >> ac.p >> ac.m;
        ac.a--;
        //ac.b--;
    }

    int maxsubsets = (1 << m) - 1;
    int temperature[100];
    int mincost = INT32_MAX;
    for(int i = 0; i < maxsubsets; i++) {
        fill_n(temperature, 100, 0); // reset

        int cost = 0;
        for(int j = 0; j < m; j++) {
            if((i & (1 << j)) != 0) {
                cost += acs[j].m;

                for(int k = acs[j].a; k < acs[j].b; k++) {
                    temperature[k] += acs[j].p;
                }
            }
        }

        bool good = true;
        for(Cow c : cows) {
            for(int k = c.s; k < c.t; k++) {
                if(c.c > temperature[k]) {
                    good = false;
                    break;
                }
            }

            if(!good) {
                break;
            }
        }

        if(good) {
            mincost = min(mincost, cost);
        }
    }

    cout << mincost << '\n';
    return 0;
}