#include <bits/stdc++.h>
#include <iostream>

using namespace std;

/*
sort all things first by x increasing then by y increasing

we will get some columns that looks like this

5
4
3     x
2       x
1 x   x x x
0 1 2 3 4 5

dp[i] => answer if last apple we jumped to was a[i] which is the sorted order
we can only jump to apples to the right and taller which isnt too hard with seg tree and inserting in reverse 
calculating cost is a pain

*/