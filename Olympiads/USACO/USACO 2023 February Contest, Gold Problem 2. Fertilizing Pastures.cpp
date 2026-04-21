#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2e5+5;
#define int long long

int n, a[MAXN], dp[MAXN][2],sz[MAXN], sm[MAXN], depth[MAXN], mx, tt;

vector<int> adj[MAXN];

/*
cost will be di * ai + some penalty to do with t 

penalty will sum to t(a1, a2, a3...) in subtree, thus we transition to lowest sum subtree
*/

void dfs(int node, int par){
    sm[node] = a[node];
    sz[node] = 1;

    mx = max(mx, depth[node]);

    for(int child : adj[node]){
        if(child == par) continue;
        depth[child] = depth[node] + 1;
        dfs(child, node);
        
        sm[node] += sm[child];
        sz[node] += sz[child];
    }

}


void dfs2(int node, int par){
    vector<pair<int,pair<int,int>>> c;

    for(int child : adj[node]){
        if(child == par) continue;
        dfs2(child, node);

        c.push_back({-sm[child], {sz[child], child}});

    }

    //sum / sz <= sum sz
    sort(c.begin(), c.end(), [](auto a, auto b){
        return -a.first * b.second.first > -b.first * a.second.first;
    });
    
    vector<int> suf(c.size()+1);
    vector<int> val(c.size());

    int t = 1;
    for(int i = 0; i < c.size(); i++){
        dp[node][0] += dp[c[i].second.second][0] + sm[c[i].second.second] * t;
        val[i] = t;
        t += 2 * (c[i].second.first);
    }

    for(int i = c.size()-1; i >= 0; i--) suf[i] = suf[i+1] + sm[c[i].second.second];

    



    if(depth[node] == mx) dp[node][1] = 0;


    for(int i = 0; i < c.size(); i++)
        dp[node][1] = min(dp[node][1], dp[node][0] - suf[i+1] * 2 * c[i].second.first - 
        dp[c[i].second.second][0] - sm[c[i].second.second] * val[i] + (t - 2 * c[i].second.first) * sm[c[i].second.second] + dp[c[i].second.second][1]);






}



int32_t main(){
    cin >> n >> tt;

    dp[1][1] = 2e18;
    for(int i = 2; i <= n; i++){
        int x; cin >> x >> a[i];
        dp[i][1] = 2e18;

        adj[x].push_back(i);
    }

    dfs(1,-1);
    dfs2(1,-1);
    if(!tt) cout << 2 * (n-1) << " " << dp[1][0] << "\n";
    else cout << 2 * (n-1) - mx << " " << dp[1][1] << "\n";
    
}
