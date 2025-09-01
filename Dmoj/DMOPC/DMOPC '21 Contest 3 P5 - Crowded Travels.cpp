#include <bits/stdc++.h>
#include <iostream>

using namespace std;

/*
dp for expect to reach 1 and expected to come back to myself

dp[i][0] for reach 1
dp[i][1] for reach myself again

dp[i][1] = 1 for uncrowded or leaf
dp[u][1] = sum 1/deg(v) + dp[v][1]
*/