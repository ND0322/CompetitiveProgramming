#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
#define INF 0x3f3f3f3f
vector<vector<pii>> adj(19);
vector<vector<int>> dp(18,vector<int>(pow(2,18)-1,-1));
int n;

int solve(int node, int vis){
  
  vis = vis|(1 << node);
  if(node == n-1){
    return 0;
  }
  if(vis == pow(2,n)-1){
    cout << node << vis << endl;
    return -INF;
  }

  if(dp[node][vis] == -1){
    int big = -INF;
    for(pii i:adj[node]){
      int child = i.first;
      int weight = i.second;
  
      if(!(vis & (1 << child))){
        big = max(big,solve(child,vis|(1<<child)) + weight);
      }
    }
    dp[node][vis] = big;
  }

  return dp[node][vis];
  
}

int main() {
  int m; cin >> n >> m;
  

  while(m--){
    int x, y, c; cin >> x >> y >> c;
    adj[x].push_back(make_pair(y,c));
  }

  cout << solve(0,0) << endl;

  
}