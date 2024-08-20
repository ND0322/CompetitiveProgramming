#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define int long long

const int MAXN = 1e5+5;
const int MOD = 1e9+7;

int n, m, dp[MAXN], cnt[MAXN], in[MAXN];

vector<int> adj[MAXN];

bool vis[MAXN];

void solve(int node){
    if(vis[node]) return;
    if(adj[node].empty()){
        dp[node] = 0;
        cnt[node] = 1;
        return;
    }

    vis[node] = 1;

    for(int child : adj[node]){
        solve(child);
        dp[node] = (dp[node] + cnt[child] + dp[child]) % MOD;
        cnt[node] = (cnt[node] + cnt[child]) % MOD;
    }
}

int32_t main(){
    cin >> n >> m;

    for(int i = 1; i <= m; i++){
        int x,y; cin >> x >> y;

        adj[x].push_back(y);
        in[y]++;
    }

    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(in[i]) continue;
        solve(i);
        ans = (ans + dp[i]) % MOD;
    }

    cout << ans << "\n";
}