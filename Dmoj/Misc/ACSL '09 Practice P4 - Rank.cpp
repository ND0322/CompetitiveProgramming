#include <bits/stdc++.h>
#include <iostream>
#include <stack>

using namespace std;

const int MAXN = 30;

//why such low constraints


int n, m;

vector<int> adj[MAXN];

bool vis[MAXN];


bool dfs(int node, int src){
    if(vis[node] && node == src) return 1;
    else if(vis[node]) return 0;


    vis[node] = 1;

    for(int child : adj[node]){
        if(dfs(child, src)) return 1;
    }

    return 0;
}

int main(){
    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int x,y,a,b; cin >> x >> y >> a >> b;

        if(a > b) adj[x].push_back(y);
        else adj[y].push_back(x);
    }

    //cout << adj[3].size() << "\n";

    int ans = 0;

    for(int i = 1; i <= n; i++){
        fill(vis+1, vis+n+1, 0);
        ans += dfs(i,i);
    }

    cout << ans << "\n";
}

