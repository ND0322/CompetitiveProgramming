#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1e5+5;

int n,a[MAXN],cnt[MAXN];

bool can(int x){
  fill(cnt,cnt+n,0);

  for(int i = 0; i < x-1; i++){
    cnt[a[i]]++;
  }

  int tot = 0;

  for(int i = 1; i <= n; i++){
    tot += cnt[i];

    if(tot >= i) return false;
  }

  return true;

  

  
}

int main() {

  freopen("greedy.in","r",stdin);
  freopen("greedy.out","w",stdout);
  cin >> n;

  for(int i = 0; i < n; i++){
    int x; cin >> x;

    a[i] = n-x;
  }

  int lo = 1;
  int hi = n+1;
  int ans = -1;

  while(lo <= hi){
    int mid = (lo+hi)/2;

    if(can(mid)){
      lo = mid+1;
      ans = mid;
    }
    else{
      hi = mid-1;
    }
  }

  cout << n-ans << "\n";
}