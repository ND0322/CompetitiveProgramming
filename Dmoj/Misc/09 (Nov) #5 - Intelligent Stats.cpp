#include <bits/stdc++.h>
#include <iostream>
#include <map>

using namespace std;

const int MAXN=  2e4+5;

int n, m, dp[MAXN];

bool vis[MAXN];

vector<int> adj[MAXN];

map<string, int> id;


void dfs(int node){
    vis[node] = 1;
    for(int child : adj[node]){
        if(vis[child]) continue;
        dfs(child);
        dp[node] += dp[child]+1;
    }
}
int main(){
    cin >> m;

    for(int i = 0; i < m; i++){
        string x, y; cin >> x >> y;

        if(!id.count(x)) id[x] = id.size()+1;
        if(!id.count(y)) id[y] = id.size()+1;
            
        

        adj[id[x]].push_back(id[y]);
    }


    for(int i = 1; i <= id.size(); i++){
        if(!vis[i]) dfs(i);
    }
    cout << id.size() << "\n";

    for(auto [x,y] : id){
        cout << x << " " << dp[y] << "\n";
    }


}