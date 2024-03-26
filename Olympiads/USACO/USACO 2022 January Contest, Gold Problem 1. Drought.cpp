#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 105;
const int MOD = 1e9+7;

/*
even build up from 0
odd build up from i for all i 
*/

int n, a[MAXN], dp[MAXN][1005];

int solve(int x){
    memset(dp, 0, sizeof(dp));
    for(int i = 0; i <= a[n]-x; i++) dp[n][i] = 1;
    for(int i = n-1; i >= 1; i--){
        for(int j = 0; j <= a[i]-x; j++){
            for(int k = 0; k+j <= a[i]-x; k++) dp[i][j] = (dp[i][j] + dp[i+1][k]) % MOD;
            
        }
    }
    return dp[1][0];
}

int main(){
    cin >> n;

    for(int i = 1; i <= n; i++) cin >> a[i];

    long long ans = 0;
    if(n&1){
        for(int i = 0; i <= 1000; i++) ans = (ans + solve(i)) % MOD;
    }
    else ans = solve(0);

    cout << ans << "\n";
}