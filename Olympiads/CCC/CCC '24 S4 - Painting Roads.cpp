#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2e5+5;

char ans[MAXN];

bool vis[MAXN];

vector<pair<int,int>> adj[MAXN], adjt[MAXN];

void dfs(int node){
    vis[node] = 1;

    for(auto [child,id] : adj[node]){
        if(vis[child]) continue;

        adjt[node].push_back({child,id});
        adjt[child].push_back({node,id});
        dfs(child);
    }
}

void color(int node, int par, bool col){
    vis[node] = 1;
    for(auto [child,id] : adjt[node]){
        if(child == par) continue;
        ans[id] = (col ? 'R' : 'B');
        color(child, node, !col);
    }
}

int main(){
    int n,m; cin >> n >> m;


    for(int i = 0; i < m; i++){
        int x,y; cin >> x >> y;

        adj[x].push_back({y,i});
        adj[y].push_back({x,i});
    }

    memset(ans,'G', sizeof(ans));
   
    for(int i = 1; i <= n; i++){
        if(!vis[i]) dfs(i);
    }

    memset(vis,0,sizeof(vis));

    for(int i = 1; i <= n; i++){
        if(!vis[i]) color(i,-1,0);
    }

    for(int i = 0; i < m; i++) cout << ans[i];    
}