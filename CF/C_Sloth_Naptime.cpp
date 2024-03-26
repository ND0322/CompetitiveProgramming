#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 3e5+5;
const int MAXD = 19;

int n, q, jmp[MAXN][MAXD], depth[MAXN];

vector<int> adj[MAXN];
void dfs(int node){
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

int main(){
    cin >> n;

    for(int i = 0; i < n-1; i++){
        int x,y; cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1);

    cin >> q;

    while(q--){
        int x,y,c; cin >> x >> y >> c;

        int a = depth[x] - depth[lca(x,y)];
        int b = depth[y] - depth[lca(x,y)];

        if(c <= a){
            cout << lift(x, c) << "\n";
            continue;
        }

        if(c <= a + b){
            cout << lift(y, b - (c-a)) << "\n";
            continue;
        }

        cout << y << "\n";


        
    }
}