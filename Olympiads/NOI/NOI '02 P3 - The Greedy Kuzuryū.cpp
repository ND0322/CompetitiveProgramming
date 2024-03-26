#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 305;
const int INF = 1e9;



int n, m,k,dp[MAXN][MAXN][2];

//node, k, this is k or not

vector<pair<int,int>> adj[MAXN];


void dfs(int node, int par){
    
    dp[node][0][0] = 0;
    dp[node][1][1] = 0;

    for(auto [child, weight] : adj[node]){
        if(child == par) continue;

        dfs(child, node);

        for(int j = k; j >= 0; j--){
            dp[node][j][0] += dp[child][0][0];
            dp[node][j][1] += dp[child][0][0];

            if(m == 2) dp[node][j][0] += weight;

            for(int l = 0; l <= j; l++){
                dp[node][j][0] = min(dp[node][j][0], dp[node][j - l][0] + min(dp[child][l][1], dp[child][l][0] + (m == 2) * weight));
                dp[node][j][1] = min(dp[node][j][1], dp[node][j - l][1] + min(dp[child][l][0], dp[child][l][1] + weight));
            }
        }
    }

}

int32_t main(){
    cin >> n >> m >> k;

    if(n-k < m){
        cout << "-1\n";
        return 0;
    }

    for(int i = 0; i < n-1; i++){
        int x,y,c; cin >> x >> y >> c;

        adj[x].push_back({y,c});
        adj[y].push_back({x,c});
    }

    memset(dp,0x3f, sizeof(dp));

    dfs(1,-1);

    cout << dp[1][k][1] << "\n";
    //cout << dp[3][1][1] << "\n";
}