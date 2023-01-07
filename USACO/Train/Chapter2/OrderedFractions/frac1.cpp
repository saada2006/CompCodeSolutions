/*
ID: shadax31
LANG: C++
TASK: frac1
*/

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <cstdio>
#include <math.h>
#include <queue>
using namespace std;
void InitIO(const char* FileName) {
    #ifndef ONLINE_JUDGE
    std::cin.tie(nullptr)->sync_with_stdio(false);
    
    constexpr std::size_t BufferSize = 256;
    char StrBuf[BufferSize];

    StrBuf[0] = '\0';
    std::snprintf(StrBuf, BufferSize, "%s.in", FileName);
    std::freopen(StrBuf, "r", stdin);

    StrBuf[0] = '\0';
    std::snprintf(StrBuf, BufferSize, "%s.out", FileName);
    std::freopen(StrBuf, "w", stdout);   
    #endif 
}

struct Fraction {
    int n, d;

    Fraction(int a, int b) : n(a), d(b) {
        simplyfy();
    }

    bool operator<(const Fraction& o) const {
        int n1 = n * o.d;
        int n2 = o.n * d;

        return (n1 < n2);  
    }

    void simplyfy() {
        if(n == 0) {
            d == 1;
            return;
        }

		int gcd = 1;
		
		if(n < d) {
			gcd = n;
		} else {
			gcd = d;
		}
		
		while(n % gcd != 0 || d % gcd != 0 )
			gcd--;
		
		n /= gcd;
		d /= gcd;
	}
};

int main() {
    InitIO("frac1");

    int n;
    cin >> n;

    set<Fraction> vals;

    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= i; j++) {
            vals.emplace(j, i);
        }
    }

    for(auto& f : vals) {
        cout << f.n << '/' << f.d << '\n';
    }
}
