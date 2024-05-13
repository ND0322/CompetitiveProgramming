#include <bits/stdc++.h>
#include <iostream>

using namespace std;

//tree dp

const int MAXN = 2e5+5;
const int INF = 1e9;

int n,dp[MAXN][20];

vector<int> adj[MAXN];

void dfs(int node){
  for(int child:adj[node]){
    dfs(child);
  }

  for(int i = 1; i < 20; i++){
    int cost = i;

    for(int child:adj[node]){
      cost += dp[child][i];

      
    }

    for(int j  = 1; j < 20; j++){
      if(i == j) continue;

      dp[node][j] = min(dp[node][j],cost);
    }
    
  }
}



int main() {
  int tt; cin >> tt;

  for(int _ = 1; _ <= tt; _++){
    cin >> n;

    for(int i = 0; i <= n; i++){
      adj[i].clear();
      for(int j = 0; j < 20; j++){
        dp[i][j] = INF;
      }
    }
  
    int temp;
  
    cin >> temp;
  
    for(int i = 2; i <= n; i++){
      int x; cin >> x;
      adj[x].push_back(i);
    }
  
    dfs(1);
  
    cout << "Case #" << _ << ": " << min(dp[1][1],dp[1][2]) << "\n";

  }
}