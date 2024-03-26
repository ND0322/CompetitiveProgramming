#include <bits/stdc++.h>
#include <iostream>

using namespace std;

//pretty simple dp

const int MAXN = 3005;
const int MOD = 1e9+7;
int n,m;

long long dp[MAXN][MAXN];

int main(){
    cin.tie(NULL) -> ios_base::sync_with_stdio(0);
    cin >> n >> m;
    

    for(int i = 0; i < MAXN; i++) dp[i][0] = dp[0][i] = 1;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            //dont place
            dp[i][j] = dp[i-1][j];

            dp[i][j] = (dp[i][j] + dp[i-1][j-1] * 4 * j) % MOD;
            
            //pairs
            if(j >= 2) dp[i][j] = (dp[i][j] + j * (j-1)/2 * dp[i-1][j-2]) % MOD;
            if(i >= 2) dp[i][j] = (dp[i][j] + j * (i-1) * dp[i-2][j-1]) % MOD;
        }
    }

    cout << dp[n][m]-1 << "\n";
}