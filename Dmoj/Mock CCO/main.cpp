#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 105;

int n,m, k, d, u,v, dp[MAXN][15];

vector<int> adj[MAXN];

vector<pair<int,pair<int,int>>> edges;
int dfs(int node, int dist){    
    if(dist == d) return node == v;
    
        
    if(dp[node][dist] != -1) return dp[node][dist];
    dp[node][dist] = 0;
    for(int child : adj[node]) dp[node][dist] += dfs(child, dist+1);
    return dp[node][dist];



}

bool f(int x){

    for(int i = 0; i < n; i++){
        adj[i].clear();
        for(int j = 0; j <= d; j++)dp[i][j] = -1;
    }
    for(auto i : edges){
        if(i.first > x) break;
        adj[i.second.first].push_back(i.second.second);
        if(i.second.second != i.second.first) adj[i.second.second].push_back(i.second.first);
    }
    


    return dfs(u,0) >= k;    
}

int main(){
    cin >> n >> m >> d >> k >> u >> v;

    while(m--){
        int x,y,c; cin >> x >> y >> c;

        edges.push_back({c, {x,y}});
    }

    sort(edges.begin(), edges.end());

 
    int lo = 0;
    int hi = 1e9;

    int ans = -1;

    while(lo <= hi){
        int mid =(lo+hi)>>1;

        if(f(mid)){
            ans = mid;
            hi = mid-1;
        }
        else lo = mid+1;
    }

    

    cout << ans << "\n";

    

}