#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1e5+5;
const int MAXD = 20;

int n, jmp[MAXN][MAXD], dp[MAXN][MAXD][7][7], tmp[7][7];

vector<int> adj[MAXN];

/*
rbs type thing comparing prefixs 

dp + some freaky matrix shit + hld 

let dp be R-B

dp[j][k]

j is R-B at start
k is R-B at end 


for each range using

6^3 transitions 
*/




void dfs(int node){
    for(int i = 1; i < MAXD; i++){
        jmp[node][i] = jmp[jmp[node][i-1]][i-1];
        for(int j = 0; j < 6; j++){
            for(int k = 0; k < 6; k++){
                for(int l = 0; l < 6; l++) dp[node][i][j][k] = max(dp[node][i][j][k], dp[node][i-1])
            }
        }
    }
}