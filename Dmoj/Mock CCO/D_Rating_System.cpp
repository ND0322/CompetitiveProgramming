#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define int long long


int32_t main() {
  int tt; cin >> tt;

  while(tt--){
    int n; cin >> n;

    int d = 0;
    int ans = 0;
    int pref = 0;
    int mx = 0;
    
    for(int i = 1; i <= n; i++){
        int x; cin >> x;

        pref += x;

        mx = max(mx, pref);

        if(pref - mx < d){
            d = pref - mx;
            ans = mx;
        }
    }

    cout << ans << "\n";
  }
}