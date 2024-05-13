#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2e5+5;

int n, k, cnt;

bool a[MAXN];
vector<int> adj[MAXN];

void dfs(int node, int par, int d){
    d += a[node];
    d *= a[node];
    if(d > k) return;
    if(adj[node].size() == 1 && node != 1){
        cnt++;
        return;
    }

    for(int child : adj[node]){
        if(child == par) continue;
        dfs(child, node, d);
    }
}

int main(){
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];

    for(int i = 0; i < n-1; i ++){
        int x,y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1,-1,0);

    cout << cnt << "\n";
}