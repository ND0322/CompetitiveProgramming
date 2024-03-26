#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 4005;

int n,dp[MAXN];

vector<int> colors;

vector<vector<int>> adj;

int dfs(int node){
    if(!adj[node].size()){
        dp[node] = colors[node];
        return colors[node];
    }

    if(dp[node] == 4005){
        dp[node] = colors[node];

        for(int child:adj[node]){
            dfs(child);
            dp[node] += dp[child];
        }
    }
    return dp[node];
    
    
    



}

int main(){
    int t; cin >> t;
    while(t--){
        cin >> n;

        colors = vector<int>(n+1,0);
        adj = vector<vector<int>>(n+1,vector<int>());

        for(int i = 2; i <= n;i++){
            int child; cin >> child;

            adj[child].push_back(i);
        }

        for(int i = 1; i <= n; i++){
            char c; cin >> c;

            if(c == 'W'){
                colors[i] = 1;
            }
            else{
                colors[i] = -1;
            }

            dp[i] = MAXN;
        }

       
        int ans = 0;
        for(int i = 1; i <= n; i++){


            
            if(!dfs(i)){
                ans++;
            }
        }

        cout << ans << "\n" ;


    }


}