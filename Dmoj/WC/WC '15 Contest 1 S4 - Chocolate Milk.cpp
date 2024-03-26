#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 205;

int n,k, a[MAXN], dp[MAXN][MAXN], dp2[MAXN][MAXN];

//easy tree dp split the k
//dp2 for within the children
vector<pair<int,int>> adj[MAXN];

void dfs(int node, int par){
    int cnt = 1;

    for(auto [child, cap] : adj[node]){
        if(child == par) continue;
        dfs(child, node);
    }

    memset(dp2, 0, sizeof(dp2));

    for(auto [child, cap] : adj[node]){
        if(child == par) continue;
        cnt++;

        for(int i = 0; i <= k; i++){
            for(int j = 0; j <= i; j++){
                dp2[cnt][i] = max(dp2[cnt][i], dp2[cnt-1][i-j] + min(dp[child][j], cap));
                if(j) dp2[cnt][i] = max(dp2[cnt][i], dp2[cnt-1][i-j] + dp[child][j-1]);
            }
        }
    }

    for(int i = 0; i <= k; i++) dp[node][i] = dp2[cnt][i] + a[node];    
}

int main(){
    cin >> n >> k;

    for(int i = 2; i <= n; i++){
        cin >> a[i];

        int x,c; cin >> x >> c;

        adj[x].push_back({i,c});
        adj[i].push_back({x,c});
    }

    dfs(1,-1);

    cout << dp[1][k] << "\n";
}