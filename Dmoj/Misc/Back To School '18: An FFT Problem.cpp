#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2005;
const int MOD = 998244353;

long long n, dp[MAXN][MAXN], a[MAXN];

int main(){
    cin >> n;

    for(int i = 1; i <= n; i++) cin >> a[i];

    dp[n+1][0] = 1;
    for(int i = n; i >= 1; i--){
        for(int j = 0; j <= n; j++){
            dp[i][j] = dp[i+1][j];

            dp[i][j] = (dp[i][j] + (dp[i+1][j-1] * a[i]) % MOD) % MOD;
            dp[i][j] = (dp[i][j] + MOD) % MOD;
        }
    }

    for(int i = 1; i <= n; i++) cout << (dp[1][i] + MOD) % MOD << " ";

    cout << "\n";
}