#include <bits/stdc++.h>
#include <iostream>

using namespace std;


const int MAXN = 2e5+5;
const int MAXD = 19; //~log2 of 2e5

//cses company queries II

int n,q, jmp[MAXN][MAXD], depth[MAXN];

vector<int> adj[MAXN];

void dfs(int node){
    for(int i = 1; i < MAXD; i++) jmp[node][i] = jmp[jmp[node][i-1]][i-1];

    for(int child : adj[node]){
        if(jmp[node][0] == child) continue;
        depth[child] = depth[jmp[child][0] = node]+1;
        dfs(child);
    }
}

int lift(int node, int d){
    for(int i = 0; i < MAXD; i++){
        if(d&(1<<i)) node = jmp[node][i]; 
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

int main(){
    cin.tie(NULL) -> ios_base::sync_with_stdio(0);
    cin >> n >> q;

    for(int i = 2; i <= n; i++){
        int x; cin >> x;

        adj[x].push_back(i);
    }

    dfs(1);

    while(q--){
        int x,y; cin >> x >> y;

        cout << lca(x,y) << "\n";
    }
}