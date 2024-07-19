#include <bits/stdc++.h>
#include <iostream>

#pragma GCC optimize("O3")
#pragma GCC target("avx2")

using namespace std;

//at most log2 n rounds of removal 
//simple tree dp after 
//my impl is not the best but me lazy 

const int MAXN = 3e5+5;
const int MAXB = 20;

int n;

long long dp[MAXN][MAXB+5], a[MAXN], sm[MAXB+5];

vector<int> adj[MAXN];

void dfs(int node, int par){
    for(int child : adj[node]){
        if(child == par) continue;
        dfs(child, node);
    }

    memset(sm, 0, sizeof(sm));

    for(int j = 0; j < MAXB; j++){
        for(int child : adj[node]) sm[j] += dp[child][j];
    }

    //subtract the thing here

    for(int i = 0; i <= MAXB; i++){

        dp[node][i] = 1e18;
        for(int j = 0; j < MAXB; j++){
            if(i == j) continue;
            dp[node][i] = min(dp[node][i], sm[j] + (j+1) * a[node]);
        }
    }
}

int main(){
    cin.tie(NULL) -> ios_base::sync_with_stdio(0);
    int tt; cin >> tt;

    while(tt--){
        cin >> n;

        for(int i = 1; i <= n; i++){
            memset(dp[i], 0, sizeof(dp[i]));
            adj[i].clear();
        }

        for(int i = 1; i <= n; i++) cin >> a[i];

        if(n == 1){
            cout << a[1] << "\n";
            continue;
        }

        for(int i = 0; i < n-1; i++){
            int x,y; cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        dfs(1,-1);

        cout << dp[1][MAXB] << "\n";
    }



}

/*
            1
           / \
          2   3
         / \
        4   5
*/