#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2e5+5;

//3, 2, 10, 8, 4, 7

int n, ans;

vector<int> adj[MAXN];

int dfs(int node, int par){
    int sz = 1;
    for(int child : adj[node]){
        if(child == par) continue;  
        sz += dfs(child, node);
    }

    if(!(sz&1) && node != 1) ans++;
    return sz;
}

int main(){
    cin >> n;

    if(n&1){
        cout << "-1\n";
        return 0;
    }

    for(int i = 0 ;i < n-1; i++) {
        int x,y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1,-1);

    cout << ans << "\n";
}