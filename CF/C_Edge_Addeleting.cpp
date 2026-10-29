#include <bits/stdc++.h>
#include <iostream>

using namespace std;

/*
longest path from n to vi that doesnt pass through 1 
*/

const int MAXN = 5e5+5;
const int MAXD = 19;

int n, q, jmp[MAXN][MAXD], depth[MAXN];

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
    int tt; cin >> tt;

    while(tt--){
        cin >> n >> q;

        for(int i = 1; i <= n; i++) adj[i].clear();


        for(int i = 1; i <= n-1; i++){
            int x,y; cin >> x >> y;

            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        dfs(1);

        int ans = depth[n];
        while(q--){
            int x; cin >> x;

            if(lca(n,x) == 1) continue;
            ans = max(ans, depth[n] + depth[x] - 2 * depth[lca(n, x)] + 1);
        }

        cout << ans << "\n";



    }
}