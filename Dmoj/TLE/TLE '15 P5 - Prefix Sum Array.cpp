#include <bits/stdc++.h>
#include <iostream>

using namespace std;

/*
k = 1
bi = a1 + a2 + a3 + ... + ai

k = 2

c1 = b1 = a1
c2 = b2 + c1 = a1 + a1 + a2
c3 = b3 + c2 = a1 + a2 + a3 + a1 + a1 + a2

ci = i*a1 + (i-1) * a2 + (i-2) * a3 + ... 1 * ai

k = 3

di = ci + di-1
di = ci + ci-1 + di-2

*/