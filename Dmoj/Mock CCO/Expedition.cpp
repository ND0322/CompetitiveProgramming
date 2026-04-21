#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 3e5+5;


//parent choice, root choice
int n, dp[MAXN][2][2], rt, spec, nxt[MAXN];

bool vis[MAXN];

vector<int> adj[MAXN];

bool flag = 1;


void dfs(int node, int par){

    int sm0 = 0;
    int sm1 = 0;

    if(node == rt){
        for(int child : adj[node]){
            if(child == par) continue;
            dfs(child, node);
            sm0 += dp[child][0][0];
            sm1 += dp[child][1][1];
        }
        dp[node][0][0] = sm0;
        dp[node][0][1] = sm1 + 1; 
        return;
    }

    for(int c = 0; c < 2; c++){
        sm1 = 0;
        sm0 = 0;
        for(int child : adj[node]){
            if(child == par) continue;
            dfs(child, node);
            sm0 += dp[child][0][c];
            sm1 += dp[child][1][c];
        }
        dp[node][0][c] = max(sm0, sm1 + 1);
        dp[node][1][c] = sm0;

        if(spec == node && c){
            dp[node][0][c] = sm0;
            continue;
        }
    }
}

void cycle(int node, int par){
    if(vis[node]){
        flag = 0;
        return;
    }

    vis[node] = 1;

    for(int child : adj[node]){
        if(child == par) continue;
        cycle(child, node);
    }
}



/*
if we choose some i, we must ban all edges attached to this node 
bipartiteness 
*/
int main(){
    cin >> n;

    for(int i = 1; i <= n ;i++){
        int x; cin >> x;

        if(x == -1) continue;

        adj[x].push_back(i);
        adj[i].push_back(x);

        nxt[i] = x;
    }

    int ans = 0;

    for(int i = 1; i <= n; i++){
        if(vis[i]) continue;

        rt = i;

        if(adj[i].empty()){
            ans++;
            continue;
        }

        flag = 1;

        cycle(rt, -1);

        if(flag) spec = -1;
        else{
            spec = *adj[i].begin();

            adj[rt].erase(find(adj[rt].begin(), adj[rt].end(), spec));
            adj[spec].erase(find(adj[spec].begin(), adj[spec].end(), rt));
        }
         
        dfs(rt, -1);    

        cout << dp[rt][0][0]<< " " << dp[rt][0][1] << "\n";


        ans += max(dp[rt][0][0], dp[rt][0][1]);

        
    }

    cout << ans << "\n";



}