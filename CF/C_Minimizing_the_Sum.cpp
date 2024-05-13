#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define int long long

const int MAXN = 3e5+5;

int n, k, a[MAXN], dp[MAXN][15];

int32_t main(){
    int tt; cin >> tt;
    while(tt--){
        cin >> n >> k;

        for(int i = 1; i <= n; i++) cin >> a[i];
        

        //extend some subarray right or left
        //kinda like the swipe bs from ccc
        for(int i = 0; i <= k; i++) dp[n+1][i] = 0; 


        for(int i = n; i >= 1; i--){
            for(int j = 0; j <= k; j++){
                dp[i][j] = dp[i+1][j] + a[i];
                int mn = a[i];
                for(int l = 1; l <= j; l++){
                    if(i+l > n) break;
                    mn = min(mn, a[i+l]);
                    dp[i][j] = min(dp[i][j], dp[i+l+1][j-l] + (l+1) * mn); 
                }
            }
        }

        cout << dp[1][k] << "\n";
    }
    
}