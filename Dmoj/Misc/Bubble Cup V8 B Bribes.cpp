#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1e5+5;
const int MAXD = 18;
const int MOD = 1e9+7;

int n, k, jmp[MAXN][MAXD], depth[MAXN], a[MAXN], b[MAXN], pw[MAXN*10], ans;


vector<pair<int,int>> adj[MAXN];

void dep(int node){
    for(int i = 1; i < MAXD; i++) jmp[node][i] = jmp[jmp[node][i-1]][i-1];

    for(auto [child,t] : adj[node]){
        if(child == jmp[node][0]) continue;
        depth[child] = depth[node]+1;
        jmp[child][0] = node;
        dep(child);
    }
}

int lift(int node, int d){
    for(int i = 0; i < MAXD; i++){
        if(d & (1<<i)) node = jmp[node][i];
    }
    return node;
}

int lca(int x,int y){
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

void dfs(int node, int par, int ty){
    for(auto [child, t]: adj[node]){
        if(child == par) continue;

        dfs(child,node, t);

        a[node] += a[child];
        b[node] += b[child];
    }

    if(ty == 1) ans = (ans+pw[a[node]]-1) % MOD;
    if(ty == 2) ans = (ans+pw[b[node]]-1) % MOD;
    
}

int main(){
    cin.tie(NULL) -> ios_base::sync_with_stdio(0);
    cin >> n;

    pw[0] = 1;

    for(int i = 1; i <= 1e6; i++) pw[i] = (pw[i-1]<<1)%MOD;



    for(int i = 0; i < n-1; i++){
        int x,y,l; cin >> x >> y >> l;

        adj[x].push_back({y,l});

        if(!l) adj[y].push_back({x,l});
        else adj[y].push_back({x, l+1});

       
    }

    dep(1);

    cin >> k;

    int last = 1;

    while(k--){
        int x; cin >> x;

        a[last]++;
        b[x]++;
        a[lca(last,x)]--;
        b[lca(last,x)]--;
        last = x;
    }

    dfs(1,-1, 0);

    cout << ans << "\n";


}