#include <bits/stdc++.h>
#include <iostream>
#include <set>

using namespace std;

const int MAXN = 5005;

//bsearch over d
//find the lowest node and fill from the dth ancestor of that node

int n, k, parent[MAXN], depth[MAXN];

set<pair<int,int>> nodes;
vector<int> adj[MAXN];

void init(int node, int par){
    parent[node] = par;
    for(int child : adj[node]){
        if(child == par) continue;
        depth[child] = depth[node]+1;
        init(child, node);
    }
}

void dfs(int node, int par, int d){
    nodes.erase({depth[node], node});
    if(!d) return;

    for(int child : adj[node]){
        if(child == par) continue;
        dfs(child, node, d-1);
    }
}

bool can(int x){
    nodes.clear();
    for(int i = 1; i <= n; i++) nodes.insert({depth[i], i});

    int cnt = 0;
    while(nodes.size()){
        auto [d, node] = *nodes.rbegin();
        cnt++;
        nodes.erase(*nodes.rbegin());
        for(int i = 1; i <= x; i++) node = parent[node];


        dfs(node,node,x);
    }

    

    return cnt <= k;
}

int main(){
    cin >> n >> k;

    for(int i = 1; i < n; i++){
        int x,y; cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    init(1,1);

    int lo = 0;
    int hi = n;
    int ans = n;

    
    while(lo <= hi){
        int mid = (lo+hi)>>1;

        if(can(mid)){
            hi = mid-1;
            ans = mid;
        }
        else lo = mid+1;
    }
    


    

    cout << ans << "\n";



}