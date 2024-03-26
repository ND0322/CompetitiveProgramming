#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1e5+5;
const int MOD = 998244353;

int n;
long long dp[MAXN], cnt[MAXN][2];
vector<pair<int,bool>> adj[MAXN];
bool visited[MAXN];

void dfs(int node){
    visited[node] = 1;
    for(auto [child, c] : adj[node]){
        cnt[node][c]++;
        if(!c) dp[node] += cnt[node][1];

        if(!visited[child]) dfs(child);

        dp[node] = (dp[node] + (dp[child] + (cnt[child][0] * cnt[node][1]) % MOD) % MOD) %MOD;
        cnt[node][0] = (cnt[node][0]+cnt[child][0]) % MOD;
        cnt[node][1] = (cnt[node][1] + cnt[child][1]) % MOD;
    }
}

int main(){
    cin >> n;

    for(int i = 1; i <= n; i++){
        int m; cin >> m;

        for(int j = 0; j < m; j++){
            int x,c; cin >> x >> c;
            adj[i].push_back({x,c});
        }
    }

    dfs(1);

    cout << dp[1] << "\n";
}