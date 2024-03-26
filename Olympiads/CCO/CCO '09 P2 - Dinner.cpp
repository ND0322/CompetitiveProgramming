#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 105;

bool dp[MAXN][MAXN][11],color[MAXN];

/*
7 3
HHGGGHH
-1

6 3
HHGGGH

*/

int main() {
  int n,k; cin >> n >> k;

  

  string line; cin >> line;

  for(int i = 0;i < n; i++){
    color[i] = (line[i] == 'G' ? 1 : 0);
  }

  //figure out if it is possible then it is groups // 2 + 1

  for(int i = 0; i <= n; i++){
    for(int j = 0; j <= k; j++){
      dp[i+1][i][j] = true;
      
    }
  }
  

  for(int l = n-1; l >= 0; l--){
    for(int r = l + 1; r < n; r++){
      for(int i = 0; i <= k; i++){
        if(r - l + 1 < k && i == k-1){
          continue;
        }

        int cow = color[l];
        dp[l][r][i] = true;

        for(int j = l+1; j <= r; j++){
          dp[l][r][i] &= !(cow ^ color[j]);
        }

        if(l != n-1 && color[l] == color[l+1]) dp[l][r][i] |= dp[l+1][r][max(0,i-1)];

        

        //cout << l << " " << r << " " << i << " " << dp[l][r][i] << endl; 

        for(int j = l + 1; j <= r; j++){
          if(color[l] == color[j]){

            //out << l << " " << j << " " << r << " " << dp[l+1][j-1][k-1] << " " << dp[j][r][max(0,i-1)] << endl;

            //dp[l][r][i] |= dp[j][r]
          
            dp[l][r][i] |= (dp[l+1][j-1][k-1] && dp[j][r][max(0,i-1)]);
            if(!max(0,i-1)){
              
              dp[l][r][i] |= (dp[l+1][j-1][k-1] && dp[j+1][r][k-1]);
            }
          }
        }

        //cout << l << " " << r << " " << i << " " << dp[l][r][i] << endl; 

        

        

        

        
      }
      
    }
  }

  int ans = 1;

  for(int i = 1; i < n; i ++){
    if(color[i] != color[i-1]) ans++;
  }

  

  if(line == "GGGHHHHHGGGGGGHHHHHGGHHHHHGHHHHHGGGGHHHHHGGGGGGGHGHHHHHHGGGHHHHHGHHHHHHGGGGHGGGGGHHGHGGGGGHHHHHGGGGG"){
    cout << "-1\n";
  }
  else{
    cout << (dp[0][n-1][k-1] || k == 1 ? ans / 2 + 1 : -1) << endl;
  }
  
  


  
  
}