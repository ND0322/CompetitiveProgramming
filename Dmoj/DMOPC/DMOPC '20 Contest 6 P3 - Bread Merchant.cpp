#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 5e5+5;

int n, m;

bool bad[MAXN], choose[MAXN], vis[MAXN];

vector<int> adj[MAXN];

void dfs(int node){
    if(vis[node]) return;

    vis[node] = 1;

    if(!adj[node].size()){
        bad[node] = 1;
        return;
    }

    bool flag = 0;
    if(choose[node]){
        for(int child : adj[node]){
            dfs(child);
            if(bad[child]) flag = 1;
        }
    }
    else{
        bool check = 1;
        for(int child : adj[node]){
            dfs(child);
            check &= bad[child];
        }

        flag = check;
    }

    bad[node] = flag;
}
int main(){
    cin >> n >> m;

    for(int i = 1; i <= n; i++) cin >> choose[i];

    for(int i = 1; i <= m; i++){
        int x,y; cin >> x >> y;

        adj[x].push_back(y);
    }

    for(int i = 1; i <= n; i++){
        if(!vis[i]) dfs(i);
    }

    for(int i = 1; i < n; i++) cout << bad[i] << " ";
    cout << bad[n] << "\n";



}