#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define int long long

const int MAXN = 1e5+5;

int n, k, dp[MAXN], a[55], b[55];

int32_t main(){
    int tt; cin >> tt;

    while(tt--){
        cin >> n >> k;

        long long sm = 0;
        for(int i = 1; i <= n; i++){
            cin >> a[i] >> b[i];
            sm += b[i];
        }

        for(int i = 1; i <= sm; i++) dp[i] = 1e18;
        
       
        for(int j = 1; j <= n; j++){
            for(int i = sm; i >= b[j]; i--){
                if(dp[i - b[j]] + a[j] <= (j-1)*k) dp[i] = min(dp[i], dp[i-b[j]] + a[j]);

            }
        }

        for(int i = sm; i >= 0; i--){
            if(dp[i] != 1e18){
                cout << i << "\n";
                break;
            }
        }
        
    }


}