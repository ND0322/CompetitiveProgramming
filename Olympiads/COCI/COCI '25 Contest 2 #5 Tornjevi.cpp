#include <bits/stdc++.h>

/*
alternating subsequences 

1101100

max(#1s, #0s) - some for zeros in between 

rle and some shit maybe

each chunk ofs ones and zeros can subtract

like 

11100

can subtract 2 

consider the rle

lets say its like 3 1 4 2 5

at i contribution is -min(extra + last, a[i])
extra = max(0, extra + last - a[i])


*/