#include <iostream>
#include <vector>
#include <algorithm>

struct Coordinate {
    int x, y; 
    Coordinate(int ix = 0, int iy = 0) : x(ix), y(iy) {}
    bool operator==(const Coordinate& Other) {
        bool xe = (x == Other.x);
        bool ye = (y == Other.y);
        bool ce = (xe && ye);
        return ce;
    }
};

constexpr int DefaultGrass = 2000000000;

struct Cow { 
    char Direction;
    Coordinate Origin; 
    int GrassEaten;

    Cow(void) : GrassEaten(DefaultGrass) {}
};

struct GrassIntersection {
    Cow* Intersecter; 
    Cow* Intersected;
    int IntersecterDistance;
    int IntersectedDistance;

    bool operator<(const GrassIntersection& Other) {
        return (IntersecterDistance < Other.IntersecterDistance);
    }
};

bool NEIntersection(Cow& N, Cow& E, GrassIntersection& Intersection) {
    int XDiff = N.Origin.x - E.Origin.x;
    int YDiff = E.Origin.y - N.Origin.y;

    if(XDiff < 0 || YDiff < 0 || XDiff == YDiff) {
        return false;
    }

    if(XDiff > YDiff) {
        // N gets to intersection first, E stops
        Intersection.IntersectedDistance = XDiff;
        Intersection.IntersecterDistance = YDiff;
        Intersection.Intersecter = &N;
        Intersection.Intersected = &E;
    } else {
        // X difference is smaller, so E cuts off N earlier 
        Intersection.IntersectedDistance = YDiff;
        Intersection.IntersecterDistance = XDiff;   
        Intersection.Intersecter = &E;
        Intersection.Intersected = &N;
    }

    return true;
}

bool ComputeIntersection(Cow& Current, Cow& Intersect, GrassIntersection& Intersection) {
    if(Current.Origin == Intersect.Origin) {
        return false;
    }

    bool CurrentN = (Current.Direction == 'N');
    bool IntersectN = (Intersect.Direction == 'N');

    bool CurrentE = (Current.Direction == 'E');
    bool IntersectE = (Intersect.Direction == 'E');    

    if(CurrentN && IntersectN && Current.Origin.x == Intersect.Origin.x) {
        int MinGrassEaten = std::abs(Current.Origin.y - Intersect.Origin.y);
        if(Current.Origin.y > Intersect.Origin.y) {
            Intersection.IntersectedDistance = MinGrassEaten;    
            Intersection.IntersecterDistance = 0;    
            Intersection.Intersecter = &Current;
            Intersection.Intersected = &Intersect;
        } else {
            Intersection.IntersectedDistance = MinGrassEaten;    
            Intersection.IntersecterDistance = 0;  
            Intersection.Intersecter = &Intersect;
            Intersection.Intersected = &Current;       
        }
        return true;
    } else if(CurrentE && IntersectE && Current.Origin.y == Intersect.Origin.y) {
        int MinGrassEaten = std::abs(Current.Origin.x - Intersect.Origin.x);
        if(Current.Origin.x > Intersect.Origin.x) {
            Intersection.IntersectedDistance = MinGrassEaten;    
            Intersection.IntersecterDistance = 0;   
            Intersection.Intersecter = &Current;
            Intersection.Intersected = &Intersect;
        } else {
            Intersection.IntersectedDistance = MinGrassEaten;    
            Intersection.IntersecterDistance = 0;     
            Intersection.Intersecter = &Intersect;
            Intersection.Intersected = &Current;       
        }
        return true;
    }

    if(CurrentN && IntersectE) {
        return NEIntersection(Current, Intersect, Intersection);
    } else if(CurrentE && IntersectN) {
        return NEIntersection(Intersect, Current, Intersection);
    }

    return false;
}

int main() {
    int n;
    std::cin >> n;
    std::cin.ignore();

    std::vector<Cow> GrassEaters(n);
    for(Cow& C : GrassEaters) {
        std::cin >> C.Direction >> C.Origin.x >> C.Origin.y;
        std::cin.ignore();
    }

    std::vector<GrassIntersection> Intersections;
    Intersections.reserve(n * n);

    for(int CowIndex = 0; CowIndex < n; CowIndex++) {
        Cow& CurrentCow = GrassEaters[CowIndex];
        for(int IntersecterIndex = CowIndex + 1; IntersecterIndex < n; IntersecterIndex++) {
            Cow& IntersectingCow = GrassEaters[IntersecterIndex];
            GrassIntersection PossibleIntersection; 
            if(ComputeIntersection(CurrentCow, IntersectingCow, PossibleIntersection)) {
                Intersections.push_back(PossibleIntersection);
            }
        }
    }

    std::sort(Intersections.begin(), Intersections.end());

    for(const auto& Intersection : Intersections) {
        // Did intersecter stop before?
        // The interseecter stops before if it was intersected by another grass eater 
        // This would mean Intersection.Intersecter->GrassEaten < Intersection.IntersecterDistance
        // Then we update the intersected by taking the minimum grass eaten distance 
        // Then update intersection distance if necessary
        if(Intersection.Intersecter->GrassEaten >= Intersection.IntersecterDistance) {
            Intersection.Intersected->GrassEaten = std::min(Intersection.Intersected->GrassEaten, Intersection.IntersectedDistance);
        }
    }

    for(const Cow& C : GrassEaters) {
        if(C.GrassEaten == DefaultGrass) {
            std::cout << "Infinity\n";
        } else {
            std::cout << C.GrassEaten << '\n';
        }
    }

    return 0;
}

/*
void NEIntersection(Cow& N, Cow& E, bool& Change) {
    int XDiff = N.Origin.x - E.Origin.x;
    int YDiff = E.Origin.y - N.Origin.y;

    if(XDiff < 0 || YDiff < 0 || XDiff == YDiff) {
        return;
    }

    if(XDiff > YDiff) {
        // N gets to intersection first, E stops
        if(E.GrassEaten > XDiff) {
            Change = true;
            E.GrassEaten = XDiff;
        }
    } else {
        // X difference is smaller, so E cuts off N earlier
        if(N.GrassEaten > YDiff) {
            Change = true;
            N.GrassEaten = YDiff;
        }        
    }
}

void UpdateIntersection(Cow& Current, Cow& Intersect, bool& Change) {
    if(Current.Origin == Intersect.Origin) {
        return;
    }

    bool CurrentN = (Current.Direction == 'N');
    bool IntersectN = (Intersect.Direction == 'N');

    bool CurrentE = (Current.Direction == 'E');
    bool IntersectE = (Intersect.Direction == 'E');    

    if(CurrentN && IntersectN && Current.Origin.x == Intersect.Origin.x) {
        if(Current.Origin.y > Intersect.Origin.y) {
            int MinGrassEaten = Current.Origin.y - Intersect.Origin.y;
            if(Intersect.GrassEaten > MinGrassEaten) {
                Change = true;
                Intersect.GrassEaten = MinGrassEaten;
            }
        } else {
            int MinGrassEaten = Intersect.Origin.y - Current.Origin.y;
            if(Current.GrassEaten > MinGrassEaten) {
                Change = true;
                Current.GrassEaten = MinGrassEaten;
            }            
        }
    } else if(CurrentE && IntersectE && Current.Origin.y == Intersect.Origin.y) {
        if(Current.Origin.x > Intersect.Origin.x) {
            int MinGrassEaten = Current.Origin.x - Intersect.Origin.x;
            if(Intersect.GrassEaten > MinGrassEaten) {
                Change = true;
                Intersect.GrassEaten = MinGrassEaten;
            }
        } else {
            int MinGrassEaten = Intersect.Origin.x - Current.Origin.x;
            if(Current.GrassEaten > MinGrassEaten) {
                Change = true;
                Current.GrassEaten = MinGrassEaten;
            }            
        }
    }

    if(CurrentN && IntersectE) {
        NEIntersection(Current, Intersect, Change);
    } else if(CurrentE && IntersectN) {
        NEIntersection(Intersect, Current, Change);
    }
}
*/