#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 105;

int n, W, w[MAXN], v[MAXN];

long long dp[MAXN][MAXN * 1000];

int main(){
    cin >> n >> W;

    int sum = 0;

    for(int i = 0; i < n; i++){
        cin >> w[i] >> v[i];
        sum += v[i];
    }

    memset(dp, 0x3f, sizeof(dp));

    dp[n][0] = 0;

    for(int i = n-1; i >= 0; i--){
        for(int j = 0; j <= sum; j++){
            dp[i][j] = min(dp[i+1][j], dp[i+1][j-v[i]] + w[i]);
        }
    }
    
    

    int ans = 0;

    for(int i = 0; i <= sum; i++){
       if(dp[0][i] <= W) ans = i;
    }

    cout << ans << "\n";

    

   
    
}