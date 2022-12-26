#include <iostream>
#include <cstdint>
#include <numeric>
#include <algorithm>

bool Intersecting(std::int64_t* x0, std::int64_t* x1) {
    if(x0[0] > x1[0]) {
        std::swap(x0, x1);
    }

    return x0[1] < x1[0];
}

bool Intersecting(std::int64_t* x0, std::int64_t* y0, std::int64_t* x1, std::int64_t* y1) {
    return Intersecting(x0, x1) || Intersecting(y0, y1);
}

std::int64_t NonNegSub(std::int64_t x, std::int64_t y) {
    return std::max(x - y, (std::int64_t)0);
}

void solve() {

    std::int64_t W, H, w, h, x[2], y[2];

    std::cin >> W >> H
             >> x[0] >> y[0]
             >> x[1] >> y[1] 
             >> w >> h;

    std::int64_t dh = y[1] - y[0];
    std::int64_t dw = x[1] - x[0];


    if(!(dw + w <= W && std::max(dh, h) <= H) && !(dh + h <= H && std::max(dw, w) <= W)) {
        std::cout << -1 << '\n';
        return;
    }


    std::int64_t MoveDistance = std::numeric_limits<std::int64_t>::max();

    if((dw + w <= W && std::max(dh, h) <= H)) {
        MoveDistance = std::min(MoveDistance, 
            std::min(NonNegSub(w, x[0]), NonNegSub(x[1], W - w))
        );
    }

    if((dh + h <= H && std::max(dw, w) <= W)) {
        MoveDistance = std::min(MoveDistance, 
            std::min(NonNegSub(h, y[0]), NonNegSub(y[1], H - h))
        );
    }

    std::cout << MoveDistance << '\n';
}

int main() {
    int t;
    std::cin >> t;
    
    while(t--) {
        solve();
    }

    return 0;
}