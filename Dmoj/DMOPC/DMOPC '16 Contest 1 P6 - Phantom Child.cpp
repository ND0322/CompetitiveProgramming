#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 505;

int n,m,a[MAXN], dist[MAXN][MAXN], q;

//query 1 is bounded by n
//query 2 is bounded by n and parity
//if k <= n then it's fine
//otherwise match the parity 