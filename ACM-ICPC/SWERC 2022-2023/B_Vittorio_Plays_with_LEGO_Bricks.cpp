#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 305;

#define int long long

int n, k, a[MAXN], dp[MAXN][MAXN];

int32_t main(){
    cin >> n >> k;

    for(int i = 0; i < n; i++) cin >> a[i];

    for(int i = 0; i < n; i++) dp[i][i] = k;

    for(int i = n-1; i >= 0; i--){
        for(int j = i+1; j < n; j++){
            dp[i][j] = 1e18;
            for(int l = i; l < j; l++) dp[i][j] = min(dp[i][j], dp[i][l] + dp[l+1][j] - max(0LL, k+1 - (a[j] - a[i] + 1)/2));
        }
    }

    cout << dp[0][n-1] << "\n"; 


}