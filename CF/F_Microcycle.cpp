#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2e5+5;
const int MAXD = 20;

int n, m,parents[MAXN], jmp[MAXN][MAXD], depth[MAXN];

vector<pair<int,pair<int,int>>> edges;



int mn[MAXN][MAXD];

vector<pair<int,int>> adj[MAXN];





void dfs(int node){
    for(int i = 1; i < MAXD; i++){
        jmp[node][i] = jmp[jmp[node][i-1]][i-1];
        mn[node][i] = min(mn[node][i-1], mn[jmp[node][i-1]][i-1]);
    }
        
    for(auto [child, weight] : adj[node]){
        if(jmp[node][0] == child) continue;
        depth[child] = depth[jmp[child][0] = node] + 1;
        mn[child][0] = weight;
        dfs(child);
    }
}

pair<int,int> lift(int node, int d){
    int ans = 1e9;
    for(int i = 0; i < MAXD; i++){
        if(d & (1<<i)){
            ans = min(ans,mn[node][i]);
            node = jmp[node][i];
        }
    }
    return {node, ans};
}

pair<int,int> lca(int x, int y){
    if(depth[x] < depth[y]) swap(x,y);

    pair<int,int> tmp = lift(x, depth[x] - depth[y]);
    x = tmp.first;

    if(x == y) return {x,tmp.second};

    int ans = tmp.second;

    for(int i = MAXD-1; i >= 0; i--){
        if(jmp[x][i] != jmp[y][i]){
            ans = min(ans,mn[x][i]);
            ans = min(ans, mn[y][i]);
            x = jmp[x][i];
            y = jmp[y][i];
        }
    }

    return {jmp[x][0], min(min(mn[x][0], ans), mn[y][0])};
}

int find(int x){
    while(x != parents[x]){
        parents[x] = parents[parents[x]];
        x = parents[x];
    }
    return x;
}

bool uni(int x,int y){
    x = find(x);
    y = find(y);

    if(x == y) return 0;

    parents[x] = y;
    return 1;
}

int main(){

    int tt; cin >> tt;

    while(tt--){
        cin >> n >> m;

        edges.clear();

        for(int i = 0 ; i < m; i++){
            int x,y,c; cin >> x >> y >> c;
            edges.push_back({c,{x,y}});
        }

        sort(edges.begin(), edges.end());
        vector<pair<int,pair<int,int>>> rejected;

        for(int i = 1; i <= n; i++){
            parents[i] = i;
            adj[i].clear();
        }

        for(int i = 0; i < m; i++){
            int weight = edges[i].first;
            int x = edges[i].second.first;
            int y = edges[i].second.second;


            
            if(uni(x,y)){
                adj[x].push_back({y,weight});
                adj[y].push_back({x,weight});
            }
            else rejected.push_back({weight,{x,y}});
        }

        dfs(1);

        int ans = 1e9;

        for(auto edge : rejected){
            int weight = edge.first;
            auto [x,y] = edge.second;

            //cout << x << " " << y << "\n";

            

            ans = min(ans, max(lca(x,y).second, weight));
        }

        cout << ans << "\n";
        }
        


}