#include <bits/stdc++.h>
#include <iostream>

using namespace std;

typedef pair<int,int> pii;


const int MAXN = 5e4+5;
const int MAXD = 17; 


int n, k, jmp[MAXN][MAXD], depth[MAXN], s[MAXN], e[MAXN], dp[MAXN];



vector<int> adj[MAXN];

void dfs(int node){
    
    for(int i = 1; i < MAXD; i++) jmp[node][i] = jmp[jmp[node][i-1]][i-1];

    for(int child : adj[node]){
        if(jmp[node][0] == child) continue;
        depth[child] = depth[jmp[child][0] = node]+1;
        dfs(child);
    }
}

int bl(int node, int d){
    for(int i = 0; i < MAXD; i++){
        if(d&(1<<i)) node = jmp[node][i]; 
    }
    return node;
}

int lca(int x, int y){
    if(depth[x] < depth[y]) swap(x,y);
    x = bl(x, depth[x] - depth[y]);
    if(x == y) return x;

    for(int i = MAXD-1; i >= 0; i--){
        if(jmp[x][i] != jmp[y][i]){
            x = jmp[x][i];
            y = jmp[y][i];
        }
    }

    return jmp[x][0];
}


int dfs2(int node, int par){

    for(int child : adj[node]){
        if(child == par) continue;
        dp[node] += dfs2(child,node);
    }
    int tmp = dp[node];
    dp[node] += s[node] - e[node]/2;
    return tmp + s[node] - e[node];
}





int main(){
    freopen("maxflow.in", "r", stdin);
    freopen("maxflow.out", "w", stdout);
    cin >> n >> k;

    for(int i = 0; i < n-1; i++){
        int x,y; cin >> x >> y;


        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1);

    for(int i = 0; i < k; i++){
        int x,y; cin >> x >> y;

        s[x]++;
        s[y]++;
        e[lca(x,y)]+= 2;
    }

    //for(int i = 1; i <= n; i++) cout << a[i] << " ";
    //cout << "\n";

    dfs2(1,-1);

   

    int ans = 0;

    for(int i = 1; i <= n; i++) ans = max(ans, dp[i]);

    cout << ans << "\n";


    

   


}