#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2e5+5;

int n, m, in[MAXN], out[MAXN], dp[MAXN];

vector<int> adj[MAXN];



//longest path with removals 
//we can move to a node if it has indegree > 1 and we can move out of the node if it has outdegree > 1

void dfs(int node){
    if(out[node] <= 1){
        dp[node] = 0;
        return;
    }

    if(dp[node] != -1) return;

    dp[node] = 0;
    for(int child : adj[node]){
        dfs(child);
        if(in[child] > 1) dp[node] = max(dp[node], dp[child]+1);
    }

}

int main(){
    cin >> n >> m;

    memset(dp, -1, sizeof(dp));
    for(int i = 1; i <= m; i++){
        int x,y; cin >> x >> y;

        adj[x].push_back(y);
        out[x]++;
        in[y]++;
    }

    for(int i = 1; i <= n; i++) dfs(i);

    int ans = 0;
    for(int i = 1; i <= n; i++) ans = max(ans, dp[i]);

    cout << ans+1 << "\n";


}