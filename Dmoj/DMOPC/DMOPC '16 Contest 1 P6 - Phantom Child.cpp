#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 505;

int n,m,a[MAXN], dist[MAXN][MAXN], q;

/*
query 1 do dijkstras over ai (n^2 log m)
precompute with bfs all pairs distance
brute the end point within min(k, m) and take minimum dijsktras distance

query 2
condensation graph

brute n endpoints and check if we can reach there 

check along the path if we can make exactly k - d with any cycles we encounter 

*/
