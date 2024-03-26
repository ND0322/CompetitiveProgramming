#include <bits/stdc++.h>
#include <iostream>
#include <set>

using namespace std;

const int MAXN = 1e5+5;

int n, a[MAXN], cnt[MAXN], dp[MAXN], b[MAXN];



vector<int> adj[MAXN];

//apparently this sh is tree dp in silver




void dfs(int node, int par){
    
    cnt[node] = (node != 1 && adj[node].size() == 1);

    

    for(int child : adj[node]){
        if(child == par) continue;

        dfs(child, node);

        cnt[node] += cnt[child];
        dp[node] += dp[child];
    }

    dp[node] += b[node];
    dp[node] = min(dp[node], cnt[node]);
}

int main(){
    cin >> n;

    for(int i = 1; i <= n; i++) cin >> a[i];

    for(int i= 0; i < n-1; i++){
        int x,y; cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    int leaf = 0;

    for(int i = 1; i <= n ; i++){
        if(i != 1 && adj[i].size() == 1) leaf++;
    }

    

    for(int i = 1; i <= leaf; i++) b[a[i]]++;    
    
    dfs(1,-1);

    //cout << cnt[1] << "\n";
    cout << dp[1] << "\n";
}

/*
    1
   / \
  2   3
     / \
    4   5
*/
