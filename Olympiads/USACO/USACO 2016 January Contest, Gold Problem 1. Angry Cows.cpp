#include <bits/stdc++.h>
#include <iostream>

using namespace std;


const int INF = 2e9;


int n;
vector<int> dp1,dp2,arr;


int main() {
  freopen("angry.in", "r", stdin);
  freopen("angry.out", "w", stdout);

  
  cin >> n;

  arr = vector<int>(n);

  for(int i = 0; i < n; i++){
    cin >> arr[i];
    arr[i] *= 2;
  }

  sort(arr.begin(),arr.end());
  arr.resize(unique(arr.begin(), arr.end()) - arr.begin());

  dp1 = vector<int>(n,INF);
  dp1[0] = -2;
  int last = 0;

  for(int i = 1; i < n; i++){
    while(last + 1 < i && abs(arr[i] - arr[last+1]) > dp1[last+1]+2){
      last++;
    }

    dp1[i] = min(abs(arr[i] - arr[last]),dp1[last+1]+2);

    
  }

  reverse(arr.begin(),arr.end());

  dp2 = vector<int>(n,INF);
  dp2[0] = -2;
  last = 0;

  for(int i = 1; i < n; i++){
    while(last + 1 < i && abs(arr[i] - arr[last+1]) > dp2[last+1]+2){
      last++;
    }

    dp2[i] = min(abs(arr[i] - arr[last]),dp2[last+1]+2);

    
  }

  reverse(arr.begin(),arr.end());

  reverse(dp2.begin(),dp2.end());


  int ans = INF;
  int i = 0;
  int j = n-1;

  while(i<j){
    ans = min(ans,max((arr[j] - arr[i])/2, 2 + max(dp1[i],dp2[j])));

    if(dp1[i+1] < dp2[j-1]){
      i++;
    }
    else{
      j--;
    }
  }

   cout << ans / 2 << '.' << (ans % 2 ? 5 : 0) << '\n';


  
}