#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1e5+5;

#define int long long


//dp is sum of number of children in subtree with an odd/even number of 1s
int n, dp[MAXN][2], a[MAXN], cnt[MAXN][2], pcnt;

vector<int> adj[MAXN];

int ans = 0, tot = 0;

void dfs(int node, int par, int p){
    if((a[node] >> p) & 1) dp[node][1]++;
    else dp[node][0]++;


    for(int child : adj[node]){
        if(child == par) continue;  

        dfs(child, node, p);
        
        if((a[node] >> p) & 1){
            dp[node][0] += dp[child][1];
            dp[node][1] += dp[child][0];
        }
        else{
            dp[node][1] += dp[child][1];
            dp[node][0] += dp[child][0];
        }
    }
}


void reroot(int node, int par, int p){

    tot += dp[node][1] * (1<<p);
    
    for(int child : adj[node]){
        if(child == par) continue;

        //delete child from node

        if((a[node] >> p) & 1){
            dp[node][0] -= dp[child][1];
            dp[node][1] -= dp[child][0];
        }
        else{
            dp[node][1] -= dp[child][1];
            dp[node][0] -= dp[child][0];
        }

        //add node to child

        if((a[child] >> p) & 1){
            dp[child][0] += dp[node][1];
            dp[child][1] += dp[node][0];
        }
        else{
            dp[child][1] += dp[node][1];
            dp[child][0] += dp[node][0];
        }
        reroot(child, node, p);

        //undo node to child

        if((a[child] >> p) & 1){
            dp[child][0] -= dp[node][1];
            dp[child][1] -= dp[node][0];
        }
        else{
            dp[child][1] -= dp[node][1];
            dp[child][0] -= dp[node][0];
        }

        if((a[node] >> p) & 1){
            dp[node][0] += dp[child][1];
            dp[node][1] += dp[child][0];
        }
        else{
            dp[node][1] += dp[child][1];
            dp[node][0] += dp[child][0];
        }

    }
}

int32_t main(){
    cin >> n;

    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n-1; i++){
        int x,y; cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    
    for(int i =0; i < 22; i++){

        pcnt = 0;
        tot = 0;

        for(int j = 1; j <= n; j++){
            dp[j][0] = 0;
            dp[j][1] = 0;

            pcnt += (a[j] >> i) & 1; 
        }
        dfs(1, -1, i);

        reroot(1,-1, i);

        tot -= (pcnt<<i);

        tot /= 2;
        tot += (pcnt<<i);

        ans +=tot;

        




    }
    

    cout << ans << "\n";
    

}