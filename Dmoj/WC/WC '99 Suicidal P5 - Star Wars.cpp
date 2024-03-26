#include <bits/stdc++.h>
#include <iostream>

using namespace std;

//greedy n^2

const int MAXN = 105;

int n;

vector<int> adj[MAXN], path[MAXN];

vector<pair<pair<int,int>,int>> edges;


bool vis[MAXN];



void dfs(int node, int rt){
    vis[node] = 1;
    path[rt].push_back(node);
    for(int child : adj[node]){
        if(!vis[child]) dfs(child,rt);  
    }
}



void solve(){
    cin >> n;

    for(int i = 1; i <= n; i++){
        adj[i].clear();
        path[i].clear();
        vis[i] = 0;
    }

    edges.clear();
    while(1){
        int x,y,c; cin >> x >> y >> c;

        if(!x) break;

        adj[x].push_back(y);
        edges.push_back({{-1,-c},y});
    }

    for(int i = 1; i <= n; i++){
        dfs(i,i);
        memset(vis,0,sizeof(vis));
    }

    for(int i = 0; i < edges.size(); i++) edges[i].first.first = path[edges[i].second].size();

    sort(edges.rbegin(), edges.rend());

    int ans = 0;

    for(auto edge : edges){
        int x = edge.second;
        int c = -edge.first.second;

        if(vis[x]) continue;

        for(int i : path[x]) vis[i] = 1;
        ans += c;
    }

    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            cout << "IMPOSSIBLE\n";
            return;
        }
    }

    cout << ans << "\n";

    
}


int main(){
    int tt; cin >> tt;

    while(tt--) solve();
}