#include <bits/stdc++.h>
#include <iostream>
#include <deque>


using namespace std;

const int MAXN = 1e4+110;

typedef pair<int,int> pii;

int n,k,w, dp[MAXN][505][2], a[MAXN];



deque<pii> dq[505];

//val, ind


int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  //touching up before i do monotonic queue optimization
  
  int tt; cin >> tt;

  while(tt--){
    cin >> n >> k >> w;

    memset(dp,-0x3f, sizeof(dp));

    

    dp[0][0][0] = 0;
    dp[0][0][1] = 0;

    fill(a, a+n+w+5, 0);
    fill(dq,dq+k+5, deque<pii>());

   

    for(int i = 1; i <= n; i++) cin >> a[i];
    

    for(int i = 1; i <= n+w; i++) a[i] += a[i-1];

    

    dq[0].push_back({0,0});

    for(int i = 1; i <= n+w; i++){
      for(int j = k; j >= 1; j--){

        

   

        //remove expired indices
        while(!dq[j-1].empty() && dq[j-1].front().second < i-w) dq[j-1].pop_front();
        if(!dq[j-1].empty()) dp[i][j][1] = dq[j-1].front().first + a[i];
        if (i - w >= 0){
            dp[i][j][1] = max(dp[i][j][1], dp[i - w][j - 1][0] + (a[i] - a[i - w]));
        }
        //remove elements with small values
        while(!dq[j].empty() && dq[j].back().first < dp[i][j][1] - a[i]) dq[j].pop_back();


        //g(i) = dp[i][j][1] - a[i]
        dq[j].push_back({dp[i][j][1] - a[i], i});


        
      }

      for(int j = 0; j <= k; j++) dp[i][j][0] = max({dp[i][j][0], dp[i-1][j][0], dp[i-1][j][1]});

      
    }

    int ans = 0;

    for(int i= 1; i <= n+w; i++){
        for(int j = 0; j <= k; j++) ans = max({ans,dp[i][j][0], dp[i][j][1]});
    }

    cout << ans << "\n";

   
    
  }

  
}