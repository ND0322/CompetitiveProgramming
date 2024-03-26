#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 5e4+5;

int n,k,a[MAXN];

bool can(int x){
  int i = 0;

  for(int j = 0; j < k && i < n; j++){
    int e = a[i] + x* 2;
    while(i < n-1 && a[i+1] <= e){
      i++;
    }
    i++;
    
  }

  return i >= n;
}


int main() {

  freopen("angry.in","r",stdin);
  freopen("angry.out","w",stdout);
  cin >> n >> k;

  for(int i = 0; i < n; i++){
    cin >> a[i];
  }

  sort(a,a+n);


  int lo = 0;
  int hi = 1e9;
  int ans = 1e9;

  while(lo <= hi){

    int mid = lo + (hi - lo)/2;


    if(can(mid)){
      ans = min(ans,mid);
      hi = mid-1;
    }
    else{
      lo = mid+1;
    }
    
  }

  cout << lo << "\n";
}