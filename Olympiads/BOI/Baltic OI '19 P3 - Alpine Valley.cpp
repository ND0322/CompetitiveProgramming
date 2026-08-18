#include <bits/stdc++.h>
#include <iostream>

using namespace std;


#define int long long
const int MAXN = 1e5+5;
const int MAXD = 18;

int n, dp[MAXN], rt, q, s, jmp[MAXN][MAXD], mn[MAXN][MAXD], depth[MAXN], dist[MAXN];

vector<pair<int,int>> adj[MAXN];

pair<int,int> edges[MAXN];

bool spec[MAXN];

/*
Root at e
check that both nodes of the edge do not lie on the path to root

Now we assume that the blocked edge must lie on the ancestor path
between queried node and blocked find minimum path length to special node in subtree
*/


void dfs1(int node, int par){
    if(spec[node]) dp[node] = 0;

    for(auto [child, weight]: adj[node]){
        if(child == par) continue;
        depth[child] = depth[node]+1;
        dist[child] = dist[node] + weight;
        dfs1(child, node);
        dp[node] = min(dp[node], dp[child] + weight);
    }
}

void dfs(int node, int par){
    for(int i = 1; i < MAXD; i++){
        jmp[node][i] = jmp[jmp[node][i-1]][i-1];
        mn[node][i] = min(mn[node][i-1], mn[jmp[node][i-1]][i-1]);
    }

    for(auto [child, weight] : adj[node]){
        if(child == par) continue;

        
        jmp[child][0] = node;
        mn[child][0] = min(dp[child] - dist[child], dp[node] - dist[node]);
        dfs(child, node);
    }
}

pair<int,int> lift(int node, int d){
    int ans = dp[node] - dist[node];
    for(int i = 0; i < MAXD; i++){
        if(d & (1<<i)){
            ans = min(ans, mn[node][i]);
            node = jmp[node][i];
        }
    }

    return {node, ans};
}

int lca(int x, int y){
    if(depth[x] > depth[y]) swap(x,y);

    y = lift(y, depth[y] - depth[x]).first;

    if(x == y) return x;

    for(int i = MAXD-1; i >= 0; i--){
        if(jmp[x][i] != jmp[y][i]){
            x = jmp[x][i];
            y = jmp[y][i];
        }
    }

    return jmp[x][0];
}


int32_t main(){
    cin >> n >> s >> q >> rt;

    for(int i = 1; i <= n; i++){
        for(int j = 0; j < MAXD; j++) mn[i][j] = 1e17;
    }

    for(int i = 1; i < n; i++){
        int x,y,c; cin >> x >> y >> c;

        edges[i] = {x,y};
        adj[x].push_back({y,c});
        adj[y].push_back({x,c});
    }

    for(int i = 1; i <= n; i++) dp[i] = 1e17;

    for(int i = 1; i <= s; i++){
        int x; cin >> x;
        spec[x] = 1;
    }


    dfs1(rt, -1);


    dfs(rt, -1);


    while(q--){
        int i,x; cin >> i >> x;

        auto [a,b] = edges[i];

        //a be the parent
        if(depth[a] > depth[b]) swap(a,b);

        if(lca(x,b) != b){
            cout << "escaped\n";
            continue;
        }

        if(lift(x, depth[x] - depth[b]).second >= 1e16) cout << "oo\n";
        else cout << lift(x, depth[x] - depth[b]).second + dist[x] << "\n";
    
    }
}
