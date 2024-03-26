#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 205;

#define int long long

int n, dp[MAXN][MAXN];

vector<pair<int,bool>> adj[MAXN];

int gcd(int a, int b){
    return !b ? a : gcd(b, a%b);
}

void dfs(int node, int par){
    for(auto [child, t] : adj[node]){
        if(child == par) continue;

        dfs(child, node);

        //sum the children

        for(int i = 1; i <= 200; i++){
            int cur = 1e9;
            for(int j = 1; j <= 200; j++){

                
                
                if(t && gcd(i,j) > 1) cur = min(cur, dp[child][j] + j);
                if(!t && gcd(i,j) == 1) cur = min(cur, dp[child][j] + j);
            }

            dp[node][i] += cur;
        }
        
    }
}

int32_t main(){
    cin >> n;

    for(int i = 0; i < n-1; i++){
        int x,y,c; cin >> x >> y >> c;

        adj[x].push_back({y,c});
        adj[y].push_back({x,c});
    }

    dfs(1,-1);



    int ans = 1e9;
    for(int i = 1; i <= 200; i++){
        ans = min(ans, dp[1][i] + i);
    
    }

    cout << ans << "\n";
   
}

/*
    1
   / \
  4   7
 / \  |
2   5 6
      |
      3
*/