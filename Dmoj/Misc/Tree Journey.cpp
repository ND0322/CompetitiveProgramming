#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2e5+5;

int n, k, ans = 0;;

vector<int> adj[MAXN];

//assume longest path from 1 is < k

void dfs(int node, int par, int d){
    if(node != 1 && adj[node].size() == 1) ans = max(d, ans);
    for(int child : adj[node]){
        if(child == par) continue;
        dfs(child, node, d+1);
    }
}

int main(){
    cin >> n >> k;

    for(int i = 0; i < n-1; i++){
        int x,y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1,-1,0);

    if(k <= ans){
        cout << k+1 << "\n";
        return 0;
    }

    k-=ans;

    cout << ans+1 + min(k/2, n-ans-1) << "\n";

    
}