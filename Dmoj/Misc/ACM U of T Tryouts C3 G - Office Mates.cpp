#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1e5+5;

int n, m, dp[MAXN][2];

bool vis[MAXN];

vector<int> adj[MAXN];


/*
given a forest
    1
   /|\
  2 4 3
      |
      5
     / \
    6   7

    1
   /|\
  2 4 3
   / \
  5   6

dp[0] is creating a new path choosing two children
dp[1] means im already part of a path and I choose a subtree to continue to and the rest become dp[0]
*/

void dfs(int node, int par){
    vis[node] = 1;
    int sm = 0;
    for(int child : adj[node]){
        if(child == par) continue;
        dfs(child, node);
        sm += dp[child][0];
    }

    dp[node][1] = 1e9;
    bool flag = 0;
    for(int child : adj[node]){
        if(child == par) continue;
        flag = 1;
        dp[node][1] = min(dp[node][1], sm - dp[child][0] + dp[child][1]);
    }

    if(!flag) dp[node][1] = 0;
    

    
    vector<int> opt;
    for(int child : adj[node]){
        if(child == par) continue;
        opt.push_back(dp[child][1] - dp[child][0]);
    }
    sort(opt.begin(), opt.end());
    dp[node][0] = 1 + sm;
    if(opt.size()) dp[node][0] += min(opt[0], 0);
    if(opt.size() > 1) dp[node][0] += min(opt[1], 0);

    
}

int main(){
    cin.tie(NULL) -> ios_base::sync_with_stdio(0);
    int tt; cin >> tt;

    while(tt--){
        cin >> n >> m;

        for(int i = 1; i <= n; i++){
            vis[i] = 0;
            adj[i].clear();
        }

        for(int i = 0; i < m; i++){
            int x,y; cin >> x >> y;

            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        int ans = n;

        for(int i = 1; i <= n; i++){
            if(vis[i]) continue;
            dfs(i,-1);
            ans += dp[i][0];
            //cout << i << " " << dp[i][0] << " " << dp[i][1] << "\n";
        }

        cout << ans-1 << "\n";
        
    }
    

    
}