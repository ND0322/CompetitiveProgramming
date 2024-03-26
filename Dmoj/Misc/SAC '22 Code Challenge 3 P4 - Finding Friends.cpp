#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1e5+5;
const int MAXD = 17;

int n, q,jmp[MAXN][MAXD], depth[MAXN], parents[MAXN];

vector<int> adj[MAXN];


void dfs(int node){
    parents[node] = node;
    for(int i = 1; i < MAXD; i++) jmp[node][i] = jmp[jmp[node][i-1]][i-1];

    for(int child : adj[node]){
        if(child == jmp[node][0]) continue;

        jmp[child][0] = node;
        depth[child] = depth[node]+1;
        dfs(child);
    }
}

int lift(int node, int d){
    for(int i = 0; i < MAXD; i++){
        if(d & (1<<i)) node = jmp[node][i];
    }

    return node;
}

int lca(int x, int y){
    if(depth[x] < depth[y]) swap(x,y);

    x = lift(x, depth[x] - depth[y]);

    if(x == y) return x;

    for(int i = MAXD-1; i >= 0; i--){
        if(jmp[x][i] != jmp[y][i]){
            x = jmp[x][i];
            y = jmp[y][i];
        }
    }

    return jmp[x][0];
}

int find(int x){
    while(x != parents[x]){
        parents[x] = parents[parents[x]];
        x = parents[x];
    }

    return x;
}

void uni(int x, int y){
    x = find(x);
    y = find(y);

    parents[x] = y;
}

int main(){
    cin >> n >> q;

    for(int i = 0; i < n-1; i++){
        int x,y; cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);

    }

    dfs(1);

    vector<pair<int,pair<int,int>>> queries;

    for(int i = 0; i < q; i++){
        int t,x,y; cin >> t >> x >> y;

        queries.push_back({t,{x,y}});
    }

    reverse(queries.begin(), queries.end());
    vector<int> ans;


    for(auto c : queries){
        int t = c.first;
        int x = c.second.first;
        int y = c.second.second;

        if(t == 2) uni(x,y);
        else ans.push_back((find(x) != find(y)) ? -1 : depth[x] + depth[y] - 2*depth[lca(x,y)]);
    }
    
    reverse(ans.begin(), ans.end());

    for(int i : ans) cout << i << "\n";
}

