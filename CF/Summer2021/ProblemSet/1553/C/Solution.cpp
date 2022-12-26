#include <iostream>
#include <string>
#include <algorithm>

int Search(std::string Constr, int Depth, int Goals0, int Goals1) {
    if(Depth == 10) {
        return 10;
    }

    int RemainingGoals = 10 - Depth;
    int MaxGoals0 = Goals0 + ( RemainingGoals      / 2);
    int MaxGoals1 = Goals1 + ((RemainingGoals + 1) / 2);

    if(MaxGoals0 < Goals1 || MaxGoals1 < Goals0) {
        return Depth;
    }

    int NextDepth = Depth + 1;
    if(Constr[Depth] == '1') {
        if(Depth % 2 == 0)
            return Search(Constr, NextDepth, Goals0 + 1, Goals1);
        else 
            return Search(Constr, NextDepth, Goals0, Goals1 + 1);
    } 
    
    if (Constr[Depth] == '0') {
        return Search(Constr, NextDepth, Goals0, Goals1);
    }

    if (Constr[Depth] == '?') {
        int ScoreSearchTree;
        if(Depth % 2 == 0)
            ScoreSearchTree = Search(Constr, NextDepth, Goals0 + 1, Goals1);
        else 
            ScoreSearchTree = Search(Constr, NextDepth, Goals0, Goals1 + 1);
        return std::min(ScoreSearchTree, Search(Constr, NextDepth, Goals0, Goals1));
    }

    return -1;
}

void solve() {
    std::string Kicks;
    std::cin >> Kicks;

    std::cout << Search(Kicks, 0, 0, 0) << '\n';
}

int main() {
    int t;
    std::cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}