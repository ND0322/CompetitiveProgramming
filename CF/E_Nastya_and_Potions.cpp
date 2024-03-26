#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2e5+5;
const long long INF = LLONG_MAX;

typedef long long ll;

int n,m,k,cost[MAXN];
vector<int> adj[MAXN];
bool vis[MAXN];
ll dp[MAXN];

void dfs(int node){

    vis[node] = true;

    if(adj[node].empty()){
        return;
    }

    ll s = 0;

    for(int child:adj[node]){

        if(!vis[child]){
            dfs(child);
        }
        
        
        s += dp[child];

        
    }

    

    


    dp[node] = min(dp[node],s);
}

void solve(){
    cin >> n >> k;

    for(int i = 1; i <= n; i++){
        cin >> dp[i];
        vis[i] = false;
        adj[i].clear();
    }

    while(k--){
        int x; cin >> x;

        dp[x] = 0;
    }

    for(int i = 1; i<=n;i++){
        int x; cin >> x;

        for(int j = 0; j < x; j++){
            int y; cin >> y;
            adj[i].push_back({y});
        }
    }

    for(int i = 1; i <= n; i++){
        if(!vis[i]) dfs(i);
    }

    for(int i = 1; i <= n; i++){
        cout << dp[i] << " ";
    }

    cout << "\n";
}

int main(){
    int tt; cin >> tt;

    while(tt--){
        solve();
    }
}