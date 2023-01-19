#include <iostream>
#include <algorithm>
#include <utility>
#include <cstdint>

struct Rectangle {
    std::int64_t x[2];
    std::int64_t y[2];

    Rectangle(std::int64_t x0 = 0, std::int64_t x1 = 0, std::int64_t y0 = 0, std::int64_t y1 = 0) {
        x[0] = x0;
        x[1] = x1;
        y[0] = y0;
        y[1] = y1;
    }

    static Rectangle Next(void) {
        Rectangle Rect;
        std::cin >> Rect.x[0] >> Rect.y[0] >> Rect.x[1] >> Rect.y[1];
        return Rect;
    }

    static std::pair<int, int> ComputeOverlappingRange(const std::int64_t fx1, const std::int64_t lx0, const std::int64_t lx1) {
        // Assume fx and lx have been sorted so that fx begins earlier or at the same time than lx
        // If lx begins before fx ends then the start is lx[0]
        // The range is min(fx[1], lx[1]) - start

        std::pair<int, int> Range = std::make_pair(0, 0);

        if(lx0 < fx1) {
            Range.first = lx0;
            Range.second = std::min(fx1, lx1);
        }

        return Range;
    }

    static std::pair<int, int> ComputeOverlappingRange(const std::int64_t* fx, const std::int64_t* lx) {
        if(fx[0] > lx[0]) {
            std::swap(fx, lx);
        }
        return ComputeOverlappingRange(fx[1], lx[0], lx[1]);
    }

    static void SetRange(std::int64_t* a, std::pair<int, int> p) {
        a[0] = p.first;
        a[1] = p.second;
    }

    Rectangle ComputeOverlap(const Rectangle& Other) {
        Rectangle Overlap;
        SetRange(Overlap.x, ComputeOverlappingRange(x, Other.x));
        SetRange(Overlap.y, ComputeOverlappingRange(y, Other.y));
        
        return Overlap;
    }

    std::int64_t dx1x0(void) {
        return x[1] - x[0];
    }

    std::int64_t dy1y0(void) {
        return y[1] - y[0];
    }    

    std::int64_t Area() {
        return dx1x0() * dy1y0();
    }

};

int main() {
    std::cin.tie(0)->sync_with_stdio(false);

    Rectangle Paper = Rectangle::Next();
    Rectangle Blck0 = Rectangle::Next();
    Rectangle Blck1 = Rectangle::Next();

    //std::cout << "Paper Area: " << Paper.Area() << '\n';
    //std::cout << "Blck0, Blck1 Area: " << Blck0.Area() << ' ' << Blck1.Area() << '\n';

    // Compute overlap area between paper and both blck0 and blck1 and compensate using overlap of blck0 and blck1 that overlaps paper
    std::int64_t PaperVisible = Paper.Area() - Paper.ComputeOverlap(Blck0).Area() - Paper.ComputeOverlap(Blck1).Area();
    std::int64_t Compensation = Paper.ComputeOverlap(Blck0.ComputeOverlap(Blck1)).Area();
    PaperVisible += Compensation;
    std::cout << (PaperVisible != 0 ? "YES" : "NO");
}