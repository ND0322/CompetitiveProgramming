#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2e5+5;

int n, a[MAXN], b[MAXN], dp[MAXN];

vector<int> adj[MAXN];

//constructing a rooted tree is probably optimal

void dfs(int node, int par){
    dp[node] = 0;
    b[node] = 0;
    for(int child : adj[node]){
        if(child == par) continue;

        dfs(child, node);

        b[node] += b[child];
        dp[node] += dp[child];
    }

    dp[node] += (b[node] + a[node]-1) * a[node];
    b[node] += a[node];
}

int main(){
    cin >> n;

    for(int i = 1; i <= n; i++) cin >> a[i];

    for(int i = 2; i <= n; i++){
        int x; cin >> x;

        adj[x].push_back(i);
        adj[i].push_back(x);
    }

    int ans = 0;

    //this is defo wrong
    
    for(int i = 1; i <= n; i++){
        dfs(i,-1);
        //cout << i << " " << dp[i] << " " << b[i] << "\n";
        ans = max(ans,dp[i]);
    }

    

    cout << ans << "\n";
    
}