#include <bits/stdc++.h>
#include <iostream>





using namespace std;


const int MAXN = 1e5+5;
const int INF = 1e9;

int n,k,dp[MAXN],a[MAXN];


bool f[MAXN];








bool can(int x){
    fill(dp,dp+n,INF);

    dp[n] = 0;

 

    

    int lo = 0;
    int hi = n;
    int ans = -1;

    while(lo <= hi){
        int mid = (lo+hi)/2;

        cout << lo << " " << hi << "\n";

        if(a[mid] <= x){
            hi = mid+1;
            ans = mid;
        }
        else{
            lo = mid-1;
        }
    

    cout << ans << "\n";



    

    //optimize later


    /*
    for(int j = i+1; j <= n; j++){
      if(a[j] > a[i] + x) break;

      dp[i] = min(dp[i], dp[j] + 1);

      if(f[j]) break;
    }
    */
    
  }

  return dp[0] <= k;

  


  
}

int main() {
  cin >> n >> k;

  

  for(int i = 1; i <= n; i++){
    cin >> a[i] >> f[i];

    

    
  }

  can(10);

  /*
  int lo = 0;
  int hi = 1e9+5;
  int ans = -1;

  while(lo <= hi){
    int mid = (lo+hi)/2;

    if(can(mid)){
      ans = mid;
      hi = mid-1;
    }
    else{
      lo = mid+1;
    }
  }

  if(ans == -1){
    cout << "DEA Bust!\n";
  }
  else{
    cout << ans << "\n";
  }
  */

  

  

  
}