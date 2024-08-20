#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1e6+5;

int n, sz[MAXN];

vector<int> adj[MAXN];

/*
    1
   /|\
  2 3 4
 / \
5   6
*/

void dfs(int node, int par){
    for(int child : adj[node]){
        if(child == par) continue;
        dfs(child, node);
        sz[node]++;
    }
}

int main(){
    cin >> n;

    for(int i = 2; i <= n; i++){
        int x; cin >> x;

        adj[x].push_back(i);
        adj[i].push_back(x);
    }

    dfs(1,-1);

    int ans = 0;

    for(int i = 1; i <= n; i++) ans = max(ans, sz[i]);
    cout << ans+1 << '\n';
}