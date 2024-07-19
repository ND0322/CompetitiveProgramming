#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 105;

int n, dp[MAXN][MAXN][MAXN], a[MAXN];

//use range dp instead of this scuffed sh
//dp[l][r][k] => subarray with k already destroyed on the left

int main(){
    int tt; cin >> tt;

    while(tt--){
        cin >> n;
        for(int i = 1; i <= n; i++) cin >> a[i];

        
        for(int i = n; i >= 1;i--){
            for(int j = i+1; j <= n; j++){
                for(int k = 0; k <= i; k++){

                    //we can either cut a middle section or destory adjacent
                    dp[i][j][k] = dp[i+1][j][k];
                    if(i - k == a[i]) dp[i][j][k] = max({dp[i][j][k], dp[i+2][j][k+2]+1, dp[i+2][j][k]+1});

                    for(int r = i+3; r <= j; r+=2){
                        if(dp[i+1][r-1][k] == (r-i-1)/2 && a[i] == i-k) dp[i][j][k] = max({dp[i][j][k], dp[i+1][r-1][k] + dp[r+1][j][k + dp[i+1][r-1][k] + 1] + 1, dp[i+1][r-1][k] + dp[r+1][j][k] + 1});
                    }
                }
            }
        }


        cout << dp[1][n][0] << "\n";
    }

    
}