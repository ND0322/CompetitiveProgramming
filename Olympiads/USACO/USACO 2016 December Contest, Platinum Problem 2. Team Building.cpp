#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1005;
const int MOD = 1e9+9;

typedef long long ll;

int n,m,k,a[MAXN],b[MAXN];

ll dp[MAXN][MAXN][15];

int main() {

  freopen("team.in","r",stdin);
  freopen("team.out","w",stdout);
  cin >> n >> m >> k;

  for(int i = 0; i < n; i++){
    cin >> a[i];
  }

  for(int i = 0; i < m; i++){
    cin >> b[i];
  }

  sort(a,a+n);
  sort(b,b+m);

  for(int i = 0; i <= n; i++){
    for(int j = 0; j <= m; j++){
      dp[i][j][0] = 1;
    }
  }

  for(int i = n-1; i >= 0; i--){
    for(int j = m-1; j >= 0; j--){
      for(int c = 1; c <= k; c++){

        dp[i][j][c] +=dp[i+1][j][c] + dp[i][j+1][c] ;
        dp[i][j][c] -= dp[i+1][j+1][c];
        if(a[i] > b[j]){
          dp[i][j][c] += dp[i+1][j+1][c-1];
        }

        dp[i][j][c] += MOD;
        dp[i][j][c] %= MOD;
      }
    }
  }

  cout << dp[0][0][k] << "\n";
}