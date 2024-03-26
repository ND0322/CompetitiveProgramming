#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2e5+5;
typedef long long ll;

int n, q;
vector<ll> dp;
vector<vector<int>> adj;

void dfs(int node = 1, int par = -1){
    if(adj[node].size() == 1 && node != 1){
        return;
    }

    dp[node] = 0;
    for(int child:adj[node]){
        if(child == par) continue;
        dfs(child,node);

        dp[node] += dp[child];
    }
}

int main(){
    int tt; cin >> tt;

    while(tt--){
        cin >> n;

        dp = vector<ll>(n+1,1);
        adj = vector<vector<int>>(n+1,vector<int>());

        for(int i = 0; i < n-1; i++){
            int x,y; cin >> x >> y;

            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        dfs();

        int q; cin >> q;

        while(q--){
            int x,y; cin >> x >> y;

            cout << dp[x] * dp[y] << "\n";
        }


        

        
    }
}