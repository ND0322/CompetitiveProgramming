#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define int long long

int32_t main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        vector<int> l(n+1), r(n+1);

        vector<int> a(2*n+1);
        vector<int> dp(2*n+5);

        for(int i = 1; i <= 2 * n; i++){
            cin >> a[i];
            if(!l[a[i]]) l[a[i]] = i;
            else r[a[i]] = i;
        }

        for(int i = 2*n; i >= 1; i--){
            dp[i] = dp[i+1] + 1;
            
            dp[i] = max(dp[i], dp[r[a[i]]+1] + (r[a[i]] - i + 1) * (r[a[i]] - i + 1));
        }

        cout << dp[1] << "\n";


    }
}