#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1e4+5;

#define int long long

int n, c , k, sm[MAXN], edges[MAXN], a[MAXN], ans;

vector<pair<int,int>> adj[MAXN];

void dfs(int node, int par, int w){
    sm[node] += a[node];
    edges[node] += w;

    for(auto [child, weight] : adj[node]){
        if(child == par) continue;
        dfs(child, node, weight);
        sm[node] += sm[child];
        edges[node] += edges[child];
    }

    if(sm[node] >= c && edges[node] <= k && node != 1) ans++;
}

int32_t main(){
    cin >> n >> c >> k;

    for(int i = 1; i <= n; i++) cin >> a[i];

    for(int i = 0; i < n-1;i++){
        int x,y,c; cin >> x >> y >> c;

        adj[x].push_back({y,c});
        adj[y].push_back({x,c});
    }

    dfs(1, -1, 0);

    cout << ans << "\n";



}