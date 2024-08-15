#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 3e5+5;
const int MAXD = 20;

int n, jmp[MAXN][MAXD], mn[MAXN][MAXD],depth[MAXN], a,b, rt, ans = 1e9;

vector<int> adj[MAXN];

void dfs(int node){
    for(int i = 1; i < MAXD; i++){
        jmp[node][i] = jmp[jmp[node][i-1]][i-1];
        mn[node][i] = min(mn[node][i-1], mn[jmp[node][i-1]][i-1]);
    }

    for(int child : adj[node]){
        if(child == jmp[node][0]) continue;
        jmp[child][0] = node;
        mn[child][0] = node;
        depth[child] = depth[node]+1;
        dfs(child);
    }
}

pair<int,int> lift(int node, int d){
    int ans = 1e9;

    for(int i = 0; i < MAXD; i++){
        if(d & (1<<i)){
            ans = min({ans, node, mn[node][i]});
            node = jmp[node][i];
        }
    }
    return {node, ans};
}

void dfs2(int node, int par, int d){
    if(!d) ans = min(ans, lift(node, b).second);

    for(int child : adj[node]){
        if(child == par) continue;
        dfs2(child, node, (d-1) % a);
    }
    
}

int main(){
    cin >> n >> rt >> a >> b;

    if(a <= b){
        cout << 1 << "\n";
        return 0;
    }
    for(int i = 1; i <= n-1; i++){
        int x,y; cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(rt);

    cout << "ran\n";

    cout << lift(5, 3).first << "\n";

    dfs2(rt, -1, a-1);

    cout << ans << "\n";




}