#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 105;

//fairly simple range dp
//consider each bit seperately

int n, a[MAXN], cnt[MAXN][MAXN][35][2], dp[MAXN][MAXN][35];

int main(){
    cin >> n;

    for(int i = 0; i < n; i++) cin >> a[i];

    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            for(int l = i; l <= j; l++){
                for(int k = 0; k <= 30; k++) cnt[i][j][k][a[l]&(1<<k)]++;
            }
        }
    }

    for(int i = n-1; i >= 0; i--){
        for(int j = i+1; j < n; j++){
            for(int k = 0; k <= 30; k++){
                dp[i][j][k] = 1e9;

                for(int l = i; l <= j; l++) dp[i][j][k] = min(dp[i][j][k], dp[i][l][k-1] + cnt[i][l][k][1] + dp[l+1][j][k-1] + cnt[l+1][j][k][0]);
            }
        }
    }

    cout << dp[0][n-1][30] << "\n";
}