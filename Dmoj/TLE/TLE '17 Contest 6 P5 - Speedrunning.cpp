#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 5005;

int n, dp[MAXN][MAXN][2], depth[MAXN], in[MAXN], out[MAXN], t;

//node, save, must have same save at the end or no

//its just like if we let it create new in the child we add one more traversal from 1 to node with the same save point
//if not just do it



vector<pair<int,int>> adj[MAXN];

bool anc(int x, int y){
    return (in[x] < in[y] && out[y] < out[x]);
}

void pre(int node, int par){
    in[node] = t++;
    for(auto [child, weight] : adj[node]){
        if(child == par) continue;

        depth[child] = depth[node] + weight;

        pre(child, node);


    }
    out[node] = t;
}

void dfs(int node, int par){

    if(adj[node].size() == 1 && node != 1) return;
    for(auto [child, weight] : adj[node]){
        if(child == par) continue;

        dfs(child, node);
    }

    for(int i = 1; i <= n; i++){
        if(!anc(i,node) && i != 1) continue;

        for(auto [child, weight] : adj[node]){
            if(child == par) continue;

            //cant place sh
            dp[node][i][0] += dp[child][i][0] + weight;

            //consider doing this and also going once at the end from 1 and placing the checkpoint where we need

            //other we case we either put it on or not

            

        }

        dp[node][i][0] += (adj[node].size()-2) * (depth[node] - depth[i]);
        
        
       
        
    }
    
}

int main(){
    cin >> n;

    for(int i = 0; i < n-1; i++){
        int x,y,c; cin >> x >> y >> c;

        adj[x].push_back({y,c});
        adj[y].push_back({x,c});
    }

    

    pre(1,-1);
    dfs(1,-1);


    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << i << " " << j << " " << dp[i][j][0] << "\n";
        }
    }
}
