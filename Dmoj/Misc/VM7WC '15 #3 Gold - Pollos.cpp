#include <bits/stdc++.h>
#include <iostream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>





using namespace std;
using namespace __gnu_pbds;




const int MAXN = 1e5+5;
const int INF = 1e9;

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ost;

int n,k,dp[MAXN],a[MAXN],nxt[MAXN];

unordered_map<int,int> mp;


bool f[MAXN];

ost t;

/*
2 2
1 1
50 0
*/







bool can(int x){
  fill(dp,dp+n,INF);

  dp[n] = 0;

  for(int i = n-1; i >= 0; i--){

    //greedy

    int f = mp[*t.find_by_order(t.order_of_key(a[i] + x)-(mp.find(a[i]+x) == mp.end()))];

    dp[i] = dp[min(f,nxt[i])] + 1;

    

    



    

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

  int cnt = 0;

  mp[0] = 0;

  for(int i = 1; i <= n; i++){
    cin >> a[i] >> f[i];


    
    t.insert(a[i]);
    mp[a[i]] = i;

    
  }

  int last = n+2;

  for(int i = n; i >= 0; i--){
    nxt[i] = last;

    if(f[i]){
      last = i;
    }
  }

  //cout << can(1) << "\n";



  
  int lo = 1;
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
  

  

  

  
}