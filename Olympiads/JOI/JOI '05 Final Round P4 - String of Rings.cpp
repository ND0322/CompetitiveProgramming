#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 105;


bool vis[MAXN];

vector<int> adj[MAXN];

int dfs(int node, int par){
    if(vis[node]) return 0;
    vis[node] = 1;
    
    int ans = 0;
    for(int child : adj[node]){
        ans = max(ans, dfs(child, node)+1);
    }

    return ans;
}
int main(){
    int n; cin >> n;

    for(int i = 1; i <= n; i++){
        int x,y; cin >> x >> y;
        
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    int ans = 0;

    for(int i = 1; i <= n; i++){
        memset(vis, 0, sizeof(vis));

       
        ans = max(ans,  dfs(i, -1));
    }

    cout << ans << "\n";
}