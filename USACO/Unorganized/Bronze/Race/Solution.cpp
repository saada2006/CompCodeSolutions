// Copy paste for fast USACO file I/O redirection
#include <iostream>
#include <cstdio>
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

#include <cstdint>

int main() {
    InitIO("race");

    std::int64_t k, n;
    std::cin >> k >> n;

    for(std::int64_t i = 0; i < n; i++) {
        std::int64_t x;
        std::cin >> x;

        std::int64_t Travel[2] {0, 0};
        std::int64_t Time = 0;
        for(std::int64_t Speed = 1; ; Speed++) {
            Time++;
            Travel[0] += Speed;
            if(Travel[0] + Travel[1] >= k) {
                std::cout << Time << '\n';
                break;
            } else {
                if(Speed >= x) {
                    Travel[1] += Speed;
                    Time++;
                    if(Travel[0] + Travel[1] >= k) {
                        std::cout << Time << '\n';
                        break;
                    }
                }
            }
        }

    }

    return 0;
}

/*
 std::int64_t Speed = 0, Time = 0;
        for(std::int64_t Position = 0; Position < k; Position += Speed) {
            //std::cout << x << ' ' << Speed << ' ' << Position << ' ' << Time << '\n';
            Time++;
            if(Speed < x) {
                Speed++;
            } else {
                std::int64_t NextSpeed = Speed + 1;
                std::int64_t t0 = (NextSpeed * (NextSpeed + 1)) / 2;
                std::int64_t t1 = (x * (x + 1)) / 2;
                std::int64_t d = t0 - t1;
                std::int64_t EndPos = Position + d;
                //std::cout << EndPos << '\n';
                if(EndPos < k) {
                    Speed++;
                } else {
                    // Ok what if we can currently continue at our speed? 
                    t0 = (Speed * (Speed + 1)) / 2;
                    d = t0 - t1;
                    EndPos = Position + d;
                    if(Speed != x || EndPos >= k) {
                        Speed--;
                    }
                }
            }
        }
*/