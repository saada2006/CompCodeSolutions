#include <iostream>
#include <vector>
#include <numeric>
#include <set>

unsigned int gcd (unsigned int n1, unsigned int n2) {
    unsigned int tmp;
    while (n2 != 0) {
        tmp = n1;
        n1 = n2;
        n2 = tmp % n2;
    }
    return n1;
}

unsigned int lcm(unsigned int n1, unsigned int n2) {
    return (n1 * n2) / gcd(n1, n2);
}

int Search(const std::vector<int>& vec, int d) {
    for(const int x : vec) {
        std::cout << x << ' ';
    }
    std::cout << '\n';

    if(vec.size() == 0) {
        return 0;
    } else {
        int sum = 0;
        for(const int x : vec) {
            sum += d / x;
        }
        std::vector<int> lcmvals;
        lcmvals.reserve(vec.size());
        for(int i = 0; i < vec.size(); i++) {
            for(int j = i + 1; j < vec.size(); j++) {
                lcmvals.push_back(lcm(vec[i], vec[j]));
            }
        }
        std::set<int> s(lcmvals.begin(), lcmvals.end());
        lcmvals.assign(s.begin(), s.end());

        return sum - Search(lcmvals, d);
    }
}

int main() {
    int k, l, m, n, d;
    std::cin >> k >> l >> m >> n >> d;

    int ans = 0;
    for(int i = 1; i <= d; i++) {
        if(
            i % k == 0 ||
            i % l == 0 ||
            i % m == 0 ||
            i % n == 0
        ) {
            ans++;
        }
    }

    std::cout << ans << '\n';

    return 0;

    std::vector<int> init(4);
    init[0] = k;
    init[1] = l;
    init[2] = m;
    init[3] = n;
    std::cout << Search(init, d) << '\n';
    return 0;
}