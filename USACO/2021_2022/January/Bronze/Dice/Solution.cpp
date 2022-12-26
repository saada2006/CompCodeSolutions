#include <iostream>
#include <vector>
#include <algorithm>

/*
Let's first define what it means for a dice to be more likely to win more than another
Suppose I have two dices, a and b, both of which are represented by an array of integers
Then, the following equation must hold true for a to be more likely to win than b:

sum(i=1..4) sum(j=1..4) (ai > bj ? 1 : 0) > 8

In plain old english, this means that, for each possible pair of values obtianed from rolling the dice, a wins more often than b
Now, taking into account all values of dice a, b, and c must be [1, 10], this turns into a boring old brute force problem which I will not bother implementing
*/