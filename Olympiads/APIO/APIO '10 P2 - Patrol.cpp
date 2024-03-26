#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1e5+5;

int n, k, depth[MAXN], dp[MAXN], ans, parents[MAXN];

vector<int> adj[MAXN];

void dfs(int node, int par){
    parents[node] = par;
    for(int child : adj[node]){
        if(child == par) continue;
        depth[child] = depth[node]+1;
        dfs(child,node);
    }
}


//two disjoint paths
void dfs2(int node, int par){
    int best = 0;
    int sec = 0;
    for(int child : adj[node]){
        if(child == par) continue;

        dfs2(child,node);

        if(dp[child] > best){
            sec = best;
            best = dp[child];
        }
        else sec = max(sec, dp[child]);
    }

    ans = max({ans, best, best+sec});
    dp[node] += best;
}

int main(){
    cin >> n >> k;

    for(int i = 0; i < n-1; i++){
        int x,y; cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    

    dfs(1,1);

    pair<int,int> best = {-1,-1};

    for(int i = 1; i <= n; i++){
        best = max(best, {depth[i], i});
        dp[i] = 1;
    }


    int root = best.second;
    depth[best.second] = 0;

    dfs(best.second,best.second);

    best = {-1,-1};

    for(int i = 1; i <= n; i++) best = max(best, {depth[i], i});

    int node = best.second;

    while(node != parents[node]){
        dp[node] = -1;
        node = parents[node];
    }





    if(k == 1){
        cout << 2*n - 2 - best.first+1 << "\n";
        return 0;
    }

    dfs2(root,-1);

    cout << 2*n-2 - best.first - ans + 2 << "\n";




}