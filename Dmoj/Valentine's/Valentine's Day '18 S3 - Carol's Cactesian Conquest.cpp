#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 105;
const int MOD = 1e9+7;

int n, K;

long long dp[MAXN][MAXN][MAXN][2];

//i, last value, current length, done K or not

int main(){
    cin >> n >> K;

    dp[0][0][0][0] = 1;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            for(int k = 1; k <= K; k++){
                for(int b = 0; b < 2; b++){
                    for(int nxt = 0; nxt < j; nxt++) dp[i][j][k][b] = (dp[i][j][k][b] + dp[i-1][nxt][k-1][b]) % MOD;
                }

                //done the k length

                if(k == K){
                    dp[i][j][k][1] = (dp[i][j][k][1]+dp[i][j][k][0])%MOD;
                    dp[i][j][k][0] = 0;
                }
            }


            for(int b = 0; b < 2; b++){
                for(int k = j; k < i; k++){
                    for(int l = 1; l <= K; l++) dp[i][j][1][b] = (dp[i][j][1][b]+dp[i-1][k][l][b]) % MOD;

                }
            }
            
        }
    }

    long long ans = 0;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++) ans = (ans + dp[n][i][j][1]) % MOD;
    }

    cout << ans << "\n";

}