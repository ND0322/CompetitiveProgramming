#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1e5+5;

int n,m,dp[MAXN];

bool type[MAXN];
vector<int> adj[MAXN];

void dfs(int node, int par){
    for(int child:adj[node]){
        dp[node] = max(dp[node],dp[child] + (!type[node] && type[child] ? 1 : 0));
    }

    dp[node]++;
}
int main(){
    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        cin >> type[i];
    }

    for(int i = 0; i < m; i++){
        int x,y; cin >> x >>y;

        adj[x].push_back(y);
    }

    dfs(1,0);

    cout << dp[1] << endl;
}