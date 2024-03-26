#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define int long long

const int MAXN = 3e5+5;
const int MOD = 1e9+7;

int n;

long long ans, dp[MAXN][2];



//color we doin

bool a[MAXN];

vector<int> adj[MAXN];

/*
        1
       /|\
      2 3 6
      |
      5
      |
      4
*/

void dfs(int node, int par){
    dp[node][0] = 1;
    dp[node][1] = 1;
    long long ext = 0;


    for(int child : adj[node]){
        if(child == par) continue;
        dfs(child, node);
        dp[node][0] = (dp[node][0] * (dp[child][0] + 1)) % MOD;
        dp[node][1] = (dp[node][1] * (dp[child][1] + 1)) % MOD;
        ext = (ext+dp[child][!a[node]]) % MOD; 
    }

    dp[node][!a[node]] = (dp[node][!a[node]]-1)%MOD;

    dp[node][0] %= MOD;
    dp[node][1] %= MOD;

    //cout << node << " " << dp[node][0] << " " << dp[node][1] << " " << ext << "\n";

    ans = (ans+dp[node][0] + dp[node][1] - ext) % MOD;
}

int32_t main(){
    cin.tie(NULL) -> ios_base::sync_with_stdio(0);
    cin >> n;


    for(int i = 1; i <= n; i++){
        char c; cin >> c;

        //🐒
        a[i] = (c == 'R');

    }

    //cout << "\n";

    for(int i = 0; i < n-1; i++){
        int x,y; cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1,-1);

    ans %= MOD;

    ans = (ans+MOD)%MOD;

    cout << ans << "\n";
}


