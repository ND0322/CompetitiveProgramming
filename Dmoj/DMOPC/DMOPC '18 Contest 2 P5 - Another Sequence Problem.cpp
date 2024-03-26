#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 3000;
const int MOD = 1e9+7;

int n, m, k, dp[MAXN][MAXN], a[MAXN];

int main(){
    cin >> n >> m >> k;

    //if this works full is easy

    for(int i = 1; i <= k; i++) cin >> a[i];


    for(int j = 0; j <= m; j++) dp[n+1][j] = 1;

    for(int i = n; i >= 1; i--){
        for(int j = 0; j <= m; j++){
            for(int l = 1; l <= k; l++){
                if(j - a[l] >= 0) dp[i][j] = (dp[i][j]+dp[i+1][j-a[l]])%MOD;
            }
        }
    }

    cout << dp[1][m] << "\n";
}