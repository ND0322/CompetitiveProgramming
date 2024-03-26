#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

//convert to weighted graph and dijkstras

#define int long long

const int MAXN = 1e5+5;
const int MAXD = 19;



int n, m, out, jmp[MAXN][MAXD], depth[MAXN], balls[MAXN], dist[MAXN], a[MAXN];

vector<pair<int,int>> adj[MAXN], adj2[MAXN];

void dfs(int node){
    for(int i = 1; i < MAXD; i++) jmp[node][i] = jmp[jmp[node][i-1]][i-1];

    for(auto [child, w] : adj[node]){
        if(jmp[node][0] == child) continue;
        depth[child] = depth[jmp[child][0] = node]+1;
        balls[child] = balls[node]+w;
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

int32_t main(){
    cin >> n;

    for(int i = 0; i < n-1; i++){
        int x,y,c; cin >> x >> y >> c;

        adj[x].push_back({y,c});
        adj[y].push_back({x,c});
    }
    
    depth[1] = 0;

    dfs(1);

    //for(int i = 1; i <= n; i++) cout << depth[i] << "\n";

    

    cin >> m >> out;

    fill(dist,dist+m+1, 1e18);

    for(int i = 1; i <= m; i++) cin >> a[i];

    for(int i = 1; i <= m; i++){
        int k; cin >> k;

        for(int j = 0; j < k; j++){
            int x; cin >> x;


            adj2[i].push_back({x, balls[a[i]] + balls[a[x]] - 2*balls[lca(a[i],a[x])]});
        }
    }

   
    

    int s; cin >> s;

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

    for(int i = 0; i < s; i++){
        int x; cin >> x;


        dist[x] = balls[a[x]];
        pq.push({balls[a[x]],x});
    }

    

    while(!pq.empty()){
        int node = pq.top().second;
        int d = pq.top().first;

        //cout << node << " " << d << "\n";

        pq.pop();

        for(auto [child, w] : adj2[node]){

            
            if(dist[child] > d + w){
                dist[child] = d+w;
                pq.push({dist[child],child});
            }
        }
    }


    

    cout << (dist[out] == 1e18 ? -1 : dist[out]) << "\n";

}

