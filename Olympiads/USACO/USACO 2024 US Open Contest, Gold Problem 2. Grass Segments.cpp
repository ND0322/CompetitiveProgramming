#include <bits/stdc++.h>
#include <iostream>
#include <ext/pb_ds/assoc_container.hpp>

const int MAXN = 2e5+5;

int n, l[MAXN] ,r[MAXN], k[MAXN];

/*
4 cases:

lj >= li && rj <= ri
lj <= li && rj >= ri
lj < li && rj <= ri, min(rj,ri) >= k + li
lj >= li && rj > ri, max(lj, li) <= ri - k

notice how these only depend on j for one part of the inequality
look for example at case 3
it is trivial to deal with all rj > ri, so assume rj < ri
count the number of rj such that rj >= some known value and rj < some known value + number of rj > some known value
range query wit coord comp

that sh too complicated

consider only segments with at least length k
complementary count

count all the things with 
rj < li+k
lj > ri-k
with length at least k
*/