#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

typedef pair<int,int> pii;

const int MAXN = 1e4+5;
const int INF = 1e9;

int n,m,d, parents[MAXN], dp[MAXN];

vector<pii> adj[MAXN];
vector<pair<int,pii>> edges;

int find(int x){
    while(x != parents[x]){
        parents[x] = parents[parents[x]];
        x = parents[x];
    }

    return x;
}

bool uni(int x, int y){
    x = find(x);
    y = find(y);

    if(x == y) return false;

    parents[x] = y;
    return true;
}

void dfs(int node, int par){
    for(pii c: adj[node]){
        int child = c.first;
        int weight = c.second;

        if(child == par) continue;

        dp[child] = max(dp[child], min(dp[node], weight));
        dfs(child, node);
    }
}


int main(){
    cin >> n >> m >> d;

    for(int i = 0; i < m; i++){
        int x,y,c; cin >> x >> y >> c;

        edges.push_back({c,{x,y}});


    }

    for(int i = 1; i <= n; i++) parents[i] = i;

    sort(edges.begin(), edges.end());
    reverse(edges.begin(), edges.end());

    for(pair<int,pii> edge : edges){
        int weight = edge.first;
        int x = edge.second.first;
        int y = edge.second.second;

        if(uni(x,y)){
            adj[x].push_back({y,weight});
            adj[y].push_back({x,weight});
            
            if(x == 1 || y == 1) dp[1] = weight;
        }
    }

    dfs(1,-1);

    int ans = 1e9;

    for(int i = 0; i < d; i++){
        int x; cin >> x;

        ans = min(ans,dp[x]);
    }

    cout << ans << "\n";


    
}


