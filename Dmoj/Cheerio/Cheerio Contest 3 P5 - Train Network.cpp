#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2005;
const int MAXD = 11;

int n, depth[MAXN], jmp[MAXN][MAXD];

vector<int> adj[MAXN], level[MAXN];

