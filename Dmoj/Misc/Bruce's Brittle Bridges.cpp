#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define int long long

const int MAXN = 2e5+5;

int n, a[MAXN], dp[MAXN][2];

vector<pair<int,bool>> adj[MAXN];

//each edge will be used a max of 2 times
//then just select one path to end in and all other to go to and come back

//0 for comeback

void dfs(int node, int par){
    dp[node][0] = a[node];



    int best = 0;

    for(auto [child, t] : adj[node]){
        if(child == par) continue;

        dfs(child, node);

        if(t == 1) dp[node][0] += dp[child][0];
        best = max(best, dp[child][1] - t*dp[child][0]);
    }

    dp[node][1] = dp[node][0] + best;
}

int32_t main(){
    cin >> n;

    for(int i = 1; i <= n; i++) cin >> a[i];

    for(int i = 0; i < n-1; i++){
        int x,y,t; cin >> x >> y >> t;

        adj[x].push_back({y,t-1});
        adj[y].push_back({x,t-1});
    }

    dfs(1,-1);

    //cout << dp[1][0] << " " << dp[1][1] << "\n";

    cout << max(dp[1][0], dp[1][1]) << "\n";
}


