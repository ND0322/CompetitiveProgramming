#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 3e5+5;
const int MOD = 998244353;

#define int long long

int n, dp[MAXN];

//num sets of removed bois in subtree of i so that the remaining are connected

vector<int> adj[MAXN];

void dfs(int node, int par){
    dp[node] = 1;
    for(int child : adj[node]){
        if(child == par) continue;
        dfs(child,node);
        dp[node] = (dp[node] * (dp[child]+1))%MOD;
    }
}

int32_t main(){
    int tt; cin >> tt;

    while(tt--){
        cin >> n;

        for(int i = 1; i <= n; i++) adj[i].clear();
        for(int i = 1; i < n; i++){
            int x, y; cin >> x >> y;

            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        dfs(1,-1);

        long long ans = 1;

        for(int i = 1; i <= n; i++) ans = (ans + dp[i]) % MOD;
        cout << ans << "\n";

    }
}