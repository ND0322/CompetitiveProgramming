#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2e5+5;

typedef pair<int,int> pii;

vector<int> dp,id;
vector<vector<pii>> adj;
int n;

void dfs(int node){
    for(pii c:adj[node]){
        if(!dp[c.first]){
            dp[c.first] = dp[node] + (c.second <= id[node]);
            id[c.first] = c.second;

            dfs(c.first);
        }
    }
}


int main(){


    

    int t; cin >> t;

    while(t--){
        cin >> n;

        adj = vector<vector<pii>>(n+1,vector<pii>());

        for(int i = 0; i< n-1; i++){
            int x,y; cin >> x >> y;

            adj[x].push_back({y,i+1});
            adj[y].push_back({x,i+1});
        }

        dp = vector<int>(n+1,0);
        id = vector<int>(n+1,0);

        dp[1] = 1;

        dfs(1);

        int ans = 0;

        for(int i = 1; i <= n; i++){
            ans = max(ans,dp[i]);
        }

        cout << ans << "\n";
       



        

    }     
}


