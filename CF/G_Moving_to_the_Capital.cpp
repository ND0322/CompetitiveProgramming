#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

const int MAXN = 2e5+5;

int n, m, dp[MAXN][2], a[MAXN];

vector<int> adj[MAXN];

bool vis[MAXN];

int dfs(int node, bool use){
    if(dp[node][use] == -1){
        dp[node][use] = a[node];

        for(int child : adj[node]){
            if(a[child] > a[node]) dp[node][use] = min(dp[node][use], dfs(child, use));
            else if(use) dp[node][use] = min(dp[node][use], dfs(child, 0));
        }
    }
    return dp[node][use];
}

void solve(){
    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        a[i] = 0;
        vis[i] = 0;
        dp[i][0] = -1;
        dp[i][1] = -1;
        adj[i].clear();
    }

    for(int i = 0; i < m; i++){
        int x,y; cin >> x >> y;

        adj[x].push_back(y);
    }

    a[1] = 0;
    vis[1] = 1;

    queue<int> q;

    q.push(1);

    while(q.size()){
        int node = q.front();

        q.pop();

        for(int child : adj[node]){
            if(!vis[child]){
                a[child] = a[node]+1;
                vis[child] = 1;
                q.push(child);
            }
        }
    }

    for(int i = 1; i <= n; i++) cout << dfs(i,1) << " ";
    cout << "\n";



}

int main(){
    int tt; cin >> tt;

    while(tt--){
        solve();
    }
}