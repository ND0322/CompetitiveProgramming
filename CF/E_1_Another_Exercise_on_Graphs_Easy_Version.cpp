#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

const int MAXN = 405;

//dijkstras dp type thing
//for dp[u][k] if the weight is greater, then dp[v][k+1] = dp[u][k]
//otherwise dp[v][k] will equal it

int n, m, q;

vector<pair<int,int>> adj[MAXN];

pair<int,int> dp[MAXN][MAXN][MAXN];

int main(){
    int tt; cin >> tt;

    while(tt--){
        cin >> n >> m >> q;

        for(int i = 1; i <= m; i++){
            int x,y,c; cin >> x >> y >> c;

            adj[x].push_back({y,c});
            adj[y].push_back({x,c});
        }

        

        for(int i = 1; i <= n; i++){
            

            for(int j = 1; j <= n; j++){
                for(int k =1 ; k <= m; k++) dp[i][j][k] = {1e9, 1e9};
            }

            for(int k = 1; k <= m; k++){
                
            }


            

        }


        
    }
}