#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

/*
The first thing we can do is to observe that if a prefix is swapped twice, its even numbering does not change
Based on this, we can now rewrite the problem as, for each pair of cows, do we swap?

The first case: Yes we do, it bring a G-cow to the even side. Flipping moves to 2

The second case: No we don't, it brings a G-cow to the odd side. Flipping moves to 1

The third case: it doesn't matter, both cows are g-cows or h-cows. Flipping moves to 3

Suppose we now have a vector of these values, using the sample string on the problem test page, we have

GGGHGHHGHHHGHG

3112322

If we reverse the first 3, we get

3222322

Our goal is to maxize the number of 2s. To make this algorithm suitable to a greedy solution (since I doubt dp would be needed for bronze):

We would first need to go back to our idea of swapping a certain lenght twice. If we have something like this:

[already reversed to the optimal soluton]1[stuff the greedy doesn't care about yet]

We can "go back in time" and do the opisite of the optimal reversals

[already reversed to the worst solution]1[...]

Then we we revese everything up the to the stuff we don't care about yet, we not only get the optimal solution but also flip the 1

To do the math, suppose we, for a prefix, have x times we reversed y times we didn't;
It is a simple case of swap(x, y)

To know if we need a reversal, we keep track of the last value which was either 2 or 3
So our greedy algorithm would see (from the example test case):

3       do nothing

31      flip to 32

321     we reversed the last time anyway so we can implicitly changeto 322 by saying we reversed at 322

3222    last time we reversed but this time we didn't. Increment the number of non-reversals and update the last 1/2 state


*/


/*
Actually no, we cannot swap"

Suppose we have 

121212

We would first do

221212

We cannot swap our reversions because we do not have an even number of them

We would have to first do

111212

And then 

222212

So we have to double count reversions after the first one

When would you be able to swap your reversions in an overall o(n) algorithm? I have no idea

For GHHGGHHG, it is

1212

So we would do

2212    (1)
1112    (2)
2222    (3)


*/

int main() {
    int n;
    std::string s;
    std::cin >> n >> s;

    int first;
    bool saved = false;

    std::vector<int> states;
    for(int i = 0; i < n; i += 2) {
        int j = i + 1;

        char a = s[i];
        char b = s[j];

        if(!saved && a == 'G' ^ b == 'G') {
            first = i / 2;
            saved = true;
        }

        int state;
        if(a == b) {
            state = 3;
        } else {
            if(a == 'G') {
                state = 1;
            } else {
                state = 2;
            }
        }

        states.push_back(state);
    }

    int x = 0, y = 0;
    int previous = -1;

    for(int i = 0; i < n / 2; i++) {
        if(states[i] == 3 || states[i] == previous) {
            continue;
        }

        if(states[i] == 1) { // optimal to reverse
        
            if(i > first) {
                x += 2;
            } else {
                x++; 
            }
        } else { // optimal to not reverse already
            // do not reverse
            y++;
        }

        previous = states[i];
    }

    std::cout << x << '\n';
}

