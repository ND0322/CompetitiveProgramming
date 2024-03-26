#include <bits/stdc++.h>
#include <iostream>

using namespace std;



const int MAXN = 1e5+5;
const int MAXD = 18;

int n, q, jmp[MAXN][MAXD], depth[MAXN];

pair<int,int> mn[MAXN][MAXD];

vector<pair<int,int>> adj[MAXN];


pair<int,int> comb(pair<int,int> a, pair<int,int> b){
    return {max(a.first,b.first), max({a.second,b.second, min(a.first,b.first)})};
}


void dfs(int node){
    for(int i = 1; i < MAXD; i++){
        jmp[node][i] = jmp[jmp[node][i-1]][i-1];
        mn[node][i] = comb(mn[node][i-1], mn[jmp[node][i-1]][i-1]);
    }
        
    for(auto [child, weight] : adj[node]){
        if(jmp[node][0] == child) continue;
        depth[child] = depth[jmp[child][0] = node] + 1;
        mn[child][0] = {weight, -1};
        dfs(child);
    }
}

pair<int,pair<int,int>> lift(int node, int d){
    pair<int,int> ans = {-1,-1};
    for(int i = 0; i < MAXD; i++){
        if(d & (1<<i)){
            ans = comb(ans, mn[node][i]);
            node = jmp[node][i];
        }
    }
    return {node, ans};
}

pair<int,pair<int,int>> lca(int x, int y){
    if(depth[x] < depth[y]) swap(x,y);

    pair<int,pair<int,int>> tmp = lift(x, depth[x] - depth[y]);
    x = tmp.first;

    if(x == y) return {x,tmp.second};

    pair<int,int> ans = tmp.second;

    for(int i = MAXD-1; i >= 0; i--){
        if(jmp[x][i] != jmp[y][i]){
            ans = comb(ans,mn[x][i]);
            ans = comb(ans, mn[y][i]);
            x = jmp[x][i];
            y = jmp[y][i];
        }
    }

    return {jmp[x][0], comb(comb(mn[x][0], ans), mn[y][0])};
}

int main(){
    cin >> n;

    for(int i = 0; i < n-1; i++){
        int x,y,c; cin >> x >> y >> c;

        adj[x].push_back({y,c});
        adj[y].push_back({x,c});
    }

    dfs(1);

    //cout << lift(3,2).second.first << " " << lift(3,2).second.second << "\n";
    



    cin >> q;

    while(q--){
        int x,y; cin >> x >> y;

        if(x == y || jmp[x][0] == y || jmp[y][0] == x){
            cout << "-1\n";
            continue;
        }

        
        cout << lca(x,y).second.second << "\n";
    }
}



