#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define int long long

const int MAXN = 2005;

const int MOD = 1e9+7;
int n, cap, q, dp[MAXN][MAXN], a[MAXN];

int32_t main(){
    cin >> n >> cap >> q;

    for(int i = 1; i <= n; i++) cin >> a[i];

    for(int i = 0; i <= cap; i++) dp[n+1][i] = 1;
    for(int i = n; i >= 1; i--){
        for(int j = 0; j <= cap; j++){
            dp[i][j] = dp[i+1][j];

            if(j >= a[i]) dp[i][j] = (dp[i][j] + dp[i+1][j-a[i]]) % MOD;
        }
    }

    while(q--){
        int x,y,c; cin >> x >> y >> c;

        if(x < y) swap(x,y);
        for(int i = a[x]; i <= c; i++) dp[x][i] = dp[x+1][i-a[x]];
        for(int i = 0; i < a[x]; i++) dp[x][i] = 0;

        for(int i = x-1; i > y; i--){
            for(int j = 0; j <= c; j++){
                dp[i][j] = dp[i+1][j];

                if(j >= a[i]) dp[i][j] = (dp[i][j] + dp[i+1][j-a[i]]) % MOD;
            }
        }

        for(int i = a[y]; i <= c; i++) dp[y][i] = dp[y+1][i-a[y]];
        for(int i = 0; i < a[y]; i++) dp[y][i] = 0;

        for(int i = y-1; i >= 1; i--){
            for(int j = 0; j <= c; j++){
                dp[i][j] = dp[i+1][j];

                if(j >= a[i]) dp[i][j] = (dp[i][j] + dp[i+1][j-a[i]]) % MOD;
            }
        }

        cout << dp[1][c] << "\n";

        for(int i = 0; i <= c; i++) dp[x][i] = (dp[x+1][i] + dp[x+1][i-a[x]]) % MOD;
        for(int i = x-1; i > y; i--){
            for(int j = 0; j <= c; j++){
                dp[i][j] = dp[i+1][j];

                if(j >= a[i]) dp[i][j] = (dp[i][j] + dp[i+1][j-a[i]]) % MOD;
            }
        }

        for(int i = 0; i <= c; i++) dp[y][i] = (dp[y+1][i] + dp[y+1][i-a[y]]) % MOD;
        

        
        
    }
}