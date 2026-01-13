#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MOD = 1e9+7;

#define int long long

int m, n, a[105], b[105], dp[1005][105];


int32_t main(){
    cin >> m >> n;

    for(int i = 1; i <= m; i++) cin >> a[i];
    for(int i = 1; i <= m; i++) cin >> b[i];
    

    for(int i = 1;i <= m; i++) dp[n+1][i] = 1;
    for(int i = n; i >= 1; i--){
        for(int j = 1; j <= m; j++){
            //to 1 is short, to next is long

            for(int k = 1; k <= m; k++) dp[i][j] = (dp[i][j] + ((a[j] * b[k]) % MOD * dp[i+1][k]) % MOD) % MOD;
            
            for(int k = 1; k <= m; k++) dp[i][j] = (dp[i][j] + ((b[j] * a[k]) % MOD * dp[i+1][k]) % MOD) % MOD;

            for(int k = 1; k <= m; k++) dp[i][j] = (dp[i][j] + ((a[j] * a[k]) % MOD * dp[i+1][k]) % MOD) % MOD;
        }
    }

    cout << dp[1][1] << "\n";
}