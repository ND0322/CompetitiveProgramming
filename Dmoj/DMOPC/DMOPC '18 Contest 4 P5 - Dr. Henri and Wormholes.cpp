#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2e5+5;

#define int long long

int n, dp[MAXN][3], k;

vector<pair<int,pair<int,bool>>> adj[MAXN];

bool special[MAXN];

//node, comeback or no
//add rerooting or extra state for last sub

void dfs(int node, int par){
    dp[node][0] = 0;
    dp[node][1] = 0;
    dp[node][2] = 0;

    //cout << node << " " << par << "\n";
    for(auto c : adj[node]){
        int child = c.first;
        int weight = c.second.first;
        bool t = c.second.second;
        if(child == par) continue;
        dfs(child,node);

        if(t) dp[node][1] += dp[child][1] + weight*2;
    }

    dp[node][0] = dp[node][1];

    for(auto c : adj[node]){
        int child = c.first;
        int weight = c.second.first;
        bool t = c.second.second;

        if(child == par) continue;
        int res = dp[node][1];

        if(t) res -= dp[child][1] + weight*2;
        res += dp[child][0] + weight;

        dp[node][0] = max(dp[node][0], res);
    }

    dp[node][2] = dp[node][1];

    int fir = 0;
    int sec = 0;
    int opt = 0;

    for(auto c : adj[node]){
        int child = c.first;
        int weight = c.second.first;
        bool t = c.second.second;

        if(child == par) continue;

        int res = 0;

        if(t) res -= dp[child][1] + weight*2;
        if(t) opt = max(opt, dp[child][2] - dp[child][1]);
        res += dp[child][0] + weight;
        

        if(res > fir){
            sec = fir;
            fir = res;
        }
        else sec = max(sec, res);
    }

    dp[node][2] += fir + sec;
    dp[node][2] = max({dp[node][2], dp[node][1] + opt});
}


int32_t main(){
    cin.tie(NULL) -> ios_base::sync_with_stdio(0);
    cin >> n >> k;

    while(k--){
        int x; cin >> x;
        special[x] = 1;
    }

    for(int i = 0; i <n-1; i++){
        int x,y,c; cin >> x >> y >> c;

        adj[x].push_back({y,{c,special[i+1]}});
        adj[y].push_back({x,{c,special[i+1]}});
    }

    
    int ans = 0;

    dfs(1,-1);

    for(int i = 1; i <= n; i++) ans = max({ans, dp[i][0], dp[i][1], dp[i][2]});
        
    
    cout << ans << "\n";


}
