#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 5001;
const int MOD = 998244353;

int n, dp[MAXN][MAXN], psa[MAXN][MAXN][2], k;


int main(){
    cin >> n >> k;

    dp[n][n] = 1;
    psa[n][n][0] = dp[n][n];
    psa[n][n][1] = dp[n][n];

    

    for(int i = n; i >= 1; i--){
        for(int j = n; j >= 1; j--){
            if(i == j && i == n) continue;


            if(i != j || i == 1){
                if(i < j) dp[i][j] = (psa[i+1][j][0] - psa[min(i+k,n)+1][j][0] + MOD) % MOD;
                else dp[i][j] = (psa[i][j+1][1] - psa[i][min(j+k, n)+1][1] + MOD) % MOD;
            }

            psa[i][j][0] = (dp[i][j] + psa[i+1][j][0]) % MOD;
            psa[i][j][1] = (dp[i][j] + psa[i][j+1][1]) % MOD; 
        }
    }

   
    cout << dp[1][1] << "\n";
}