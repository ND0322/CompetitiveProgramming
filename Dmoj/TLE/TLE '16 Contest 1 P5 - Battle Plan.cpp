#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1e5+5;
const int MAXD = 17;

int n, jmp[MAXN][MAXD], sum[MAXN][MAXD], ans[MAXN][MAXD], depth[MAXN];

vector<pair<int,int>> adj[MAXN];


/*

binary search for next time the cost gets better and just use the answer at that node

*/

void dfs(int node){
    for(int i = 1; i < MAXD; i++){
        jmp[node][i] = jmp[jmp[node][i-1]][i-1];

        sum[node][i] = sum[node][i-1] + sum[jmp[node][i-1]][i-1];
    }
}