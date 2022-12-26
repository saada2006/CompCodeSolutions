#include <iostream>
#include <vector>

/*
If we feed a bag of corn to cows i and i+1, there new hunger level h_i and h_(i+1) both decrease by one, so the difference does not change
However, the differnce between cows i+1 and i+2 changes by 1, since i+2 is not being affected
Ideally, we want to make sure that the difference between the hunger level of each cow is zero, and each cow has a non-negative hunger level

Can we get a greedy solution to this problem? No, because we have to worry about the next cow
Let's think about it this way: if we have the entire array set to a value, can we reduce it to zero?
If we have an even number of elements, this is trivial, but what about odd? In that case, it is not possible (and setting everything to zero is incorrect whe we want to find the minimnum level)

Let's consider example cases

1 2 1
0 1 1
0 0 0

2 1 1
1 0 1 -1

8 10 5
3 5 5
3 3 3

8 10 7
5 7 7
5 5 5
*/