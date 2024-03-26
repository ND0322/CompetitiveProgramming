#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1e5+5;
const int MAXD = 17;

int n, m, k, jmp[MAXN][MAXD], depth[MAXN], dp[MAXN], in[MAXN], t;

vector<int> adj[MAXN];
pair<int,int> edges[MAXN];

void dfs(int node){
    in[node] = t++;
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

void dfs2(int node, int par){
    for(int child : adj[node]){
        if(child == par) continue;
        dfs2(child, node);

        dp[node] += dp[child];
    }
}
int main(){
    cin.tie(NULL) -> ios_base::sync_with_stdio(0);
    cin >> n >> m >> k;

    for(int i = 0; i < n-1; i++){
        int x,y; cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);

        edges[i] = {x,y};
    }

    dfs(1);

    while(m--){
        int x; cin >> x;

        vector<pair<int,int>> a(x);

        for(int i = 0; i < x; i++){
            cin >> a[i].second;

            a[i].first = in[a[i].second];
        }

        sort(a.begin(),a.end());

        a.push_back(a[0]);

        for(int i = 0; i < x; i++){
            dp[a[i].second]++;
            dp[a[i+1].second]++;
            dp[lca(a[i].second, a[i+1].second)] -= 2;
        }

    }

    dfs2(1,-1);

    vector<int> ans;

    for(int i = 0; i < n-1; i++){
        int x = edges[i].first;
        int y = edges[i].second;

        if(depth[x] < depth[y]) swap(x,y);

        if(dp[x] >= 2*k) ans.push_back(i+1);
    }

    cout << ans.size() << "\n";
    for(int i : ans) cout << i << " ";
    cout << "\n";




}