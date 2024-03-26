#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 3e5+5;

int n, ans = 1e9,sz[MAXN];

vector<int> adj[MAXN];

void dfs(int node, int par){

    sz[node] = 1;

    for(int child : adj[node]){
        if(child == par) continue;
        dfs(child,node);
        sz[node] += sz[child];
    }
}

int main(){
    cin >> n;

    for(int i = 0; i < n-1; i++){
        int x,y; cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1,-1);

    long long sum = 0;
    int ans = 0;

    for(int child : adj[1]){
        //cout << child << " " << sz[child] << "\n";
        ans = max(ans, sz[child]);
        sum += sz[child];
    }

    //cout << sum << "\n";

    cout << sum -ans+1 << "\n";
}