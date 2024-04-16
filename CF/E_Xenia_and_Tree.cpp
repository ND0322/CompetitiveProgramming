#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1e5+5;

int n, q, sz[MAXN], ans[MAXN];

bool marked[MAXN];

vector<pair<int,int>> up[MAXN];
vector<int> adj[MAXN];
void init(int node, int par){
    sz[node] = 1;

    for(int child : adj[node]){
        if(marked[child] || child == par) continue;
        init(child, node);
        sz[node] += sz[child];
    }
}

int centroid(int node, int par, int sub){
    for(int child : adj[node]){
        if(marked[child] || child == par) continue;

        if(sz[child] * 2 > sub) return centroid(child, node, sub);
    }
    return node;
}

void dist(int node, int rt, int par, int d){
    up[node].push_back({rt, d});
    for(int child : adj[node]){
        if(child == par || marked[child]) continue;
        dist(child, rt, node, d+1);
    }
}

void build(int node, int par){
    init(node, par);
    int rt = centroid(node, par, sz[node]);

    for(int child : adj[rt]){
        if(marked[child]) continue;
        dist(child, rt,rt, 1);
    }
    marked[rt] = 1;
    
    for(int child : adj[rt]){
        if(marked[child]) continue;
        build(child, rt);
    }
}

void update(int node){
    for(auto [anc, d] : up[node]) ans[anc] = min(ans[anc], d);
    ans[node] = 0;
}

int query(int node){
    int res = ans[node];
    for(auto [anc, d] : up[node]){
        if(!d) continue;
        res = min(res, ans[anc] + d);
    }
    return res;
}

int main(){
    cin >> n >> q;

    for(int i = 1; i <= n; i++) ans[i] = 1e9;
    for(int i = 0; i < n-1; i++){
        int x,y; cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }



    build(1,0);
    update(1);


   
    
    while(q--){
        int t; cin >> t;

        if(t == 1){
            int node; cin >> node;
            update(node);
        }
        else{
            int node; cin >> node;

            cout << query(node) << "\n";
        }
    }
    
    

   
}