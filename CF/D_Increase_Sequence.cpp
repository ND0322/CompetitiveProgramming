#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2005;
const int MOD = 1e9+7;

int n, k, a[MAXN];

long long dp[MAXN][MAXN];

int main(){
    cin >> n >> k;

    for(int i = 1; i <= n; i++) cin >> a[i];

    dp[n+1][0] = 1;

    for(int i = n; i >= 1; i--){
        for(int j = 0; j < i; j++){
            if(a[i] + j > k || k - a[i] - j > 1) continue;
            

            if(k == a[i] + j){
                //we can only close or skip
                dp[i][j] = dp[i+1][j];
                if(j) dp[i][j] = (dp[i][j] + dp[i+1][j-1])%MOD;
            }
            if(k == a[i] + j + 1){
                //we must open and do something else
                dp[i][j] = (dp[i+1][j+1] * (j+1))%MOD;
                dp[i][j] = (dp[i][j] + dp[i+1][j]) % MOD;
                if(j) dp[i][j] = (dp[i][j] + (dp[i+1][j] * j)%MOD)%MOD;
            }

            dp[i][j] %= MOD;

        }
    }

    cout << dp[1][0] << "\n";
}