#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1e6+5;

int n;

long long dp[MAXN][3]; 

//0 for stay in this subtree
//1 for comeback
//2 for going through this node

vector<pair<int,int>> adj[MAXN];

void dfs(int node, int par){
    dp[node][0] = 0;
    dp[node][1] = 0;
    dp[node][2] = 0;

    for(pair<int,int> c : adj[node]){
        int child = c.first;

        if(child == par) continue;
        dfs(child, node);

        if(c.second > 1) dp[node][1] += dp[child][1] + (c.second & 1 ? c.second-1 : c.second);
    }

    long long best = 0;

    for(pair<int,int> c : adj[node]){
        int child = c.first;

        if(child == par) continue;
        long long cur = max(dp[child][1], dp[child][0]) + (c.second & 1 ? c.second : c.second-1);
        if(c.second > 1) cur -= (dp[child][1] + (c.second & 1 ? c.second-1 : c.second));
        best = max(best, cur);
        
    }

    
    dp[node][0] = dp[node][1] + best;
    


    best = 0;
    long long sec = 0;
    long long opt = 0;

    for(pair<int,int> c : adj[node]){
        int child = c.first;

        if(child == par) continue;
        long long cur = dp[child][0] + (c.second & 1 ? c.second : c.second-1);
        if(c.second > 1) cur -= (dp[child][1] + (c.second & 1 ? c.second-1 : c.second));
        if(c.second > 1)  opt = max(opt, dp[child][2] + (c.second & 1 ? c.second-1 : c.second) - dp[child][1] - (c.second & 1 ? c.second-1 : c.second)); 

        if(cur > best){
            sec = best;
            best = cur;
        }
        else sec =  max(sec,cur);
    }

    dp[node][2] = dp[node][1] + best + sec;
    //if(node == 1) cout << dp[node][1] << " " << best << " " <<  sec << "\n";
    dp[node][2] = max(dp[node][2], opt + dp[node][1]);


}





int main(){
    cin.tie(NULL) -> ios_base::sync_with_stdio(0);
    
    cin >> n;
    for(int i = 0; i < n-1; i++){
        int x,y,c; cin>> x >> y >> c;
        adj[x].push_back({y,c});
        adj[y].push_back({x,c});
    }

   
    long long ans = 0;

    


    dfs(1,-1);

    for(int i = 1; i <= n; i++){
        ans = max({ans,dp[i][0], dp[i][1], dp[i][2]});
        //cout << dp[i][2] << "\n";
    }
    
    cout << ans << "\n";

    
    

}