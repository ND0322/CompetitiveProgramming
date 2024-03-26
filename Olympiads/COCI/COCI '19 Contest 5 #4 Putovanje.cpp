#include <bits/stdc++.h>
#include <iostream>

using namespace std;

typedef pair<int,int> pii;


const int MAXN = 2e5+5;
const int MAXD = 17; 


int n, jmp[MAXN][MAXD], depth[MAXN], in[MAXN], a[MAXN];

vector<pair<pii,pii>> edges;

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

void upd(int node, int par){
    in[node] = a[node];

    for(int child:adj[node]){
        if(child == par) continue;

        upd(child,node);
        in[node] += in[child];
    }
}





int main(){
    //freopen("maxflow.in", "r", stdin);
    //freopen("maxflow.out", "w", stdout);
    cin >> n;

    for(int i = 0; i < n-1; i++){
        int x,y,b,c; cin >> x >> y >> b >> c;

        edges.push_back({{x,y},{b,c}});

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1);

    for(int i = 1; i < n; i++){
        a[i]++;
        a[i+1]++;
        a[lca(i,i+1)]-= 2;
    }

    //for(int i = 1; i <= n; i++) cout << a[i] << " ";
    //cout << "\n";

    upd(1,-1);

    long long ans = 0;
    for(pair<pii,pii> p : edges){
        auto [x,y] = p.first;

        if(depth[x] < depth[y]) swap(x,y);
        //cout << a[x] << " " << p.second.second << "\n";
        ans += min(in[x] * p.second.first, p.second.second);
    }

    cout << ans << "\n";


    

   


}