#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1e4+5;

int n, q,c, dp[105][MAXN], a[105], h[105];

/*
state is cur req and cur last element


transitions dp[i][j-1]
dp[i-1][j-1] * (j-1) ^ (ri - li + li - r[i-1] - 1)


*/