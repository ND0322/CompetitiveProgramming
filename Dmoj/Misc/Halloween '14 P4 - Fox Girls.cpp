#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2e5+5;

int n, dp[MAXN][3][3], a[MAXN], spec;

vector<int> adj[MAXN];

//node, a, b
//a = 0, not colored
//a = 1, colored
//a = 2, payed for

//b = 0, rt relies on spec
//b = 1, spec relies on rt
//b = 2, no connecton


void dfs(int node, int par){

    if(node == 1){
        dp[node][2][0] = 1e9;
        dp[node][2][2] = 1e9;
    }

    if(node == spec){
        dp[node][2][1] = 1e9;
        dp[node][2][2] = 1e9;
    }

    for(int child : adj[node]){
        if(child == par) continue;

        dfs(child, node);

    }

   
}