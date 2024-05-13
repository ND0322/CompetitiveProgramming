#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>

using namespace std;

#define int long long

const int MAXN = 105;

int a[MAXN], b[MAXN], n, l, dp[MAXN][MAXN][505];




int32_t main(){
    cin >> n >> l;

    int sm = 0;
    int sb = 0;

    for(int i = 1; i <= n; i++){
        cin >> a[i];
        sm += a[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> b[i];
        sb += b[i];
    }

    for(int i = 0; i <= n+1; i++){
        for(int j = 0; j <= l; j++){
            for(int k = 0; k <= 500; k++) dp[i][j][k] = 1e18;
        }
    }
    dp[n+1][0][0] = 0;
    for(int i = n; i >= 1; i--){
        for(int j = 0; j <= l; j++){
            for(int k = 0; k <= 500; k++){
                dp[i][j][k] = dp[i+1][j][k];

                if(j && k - a[i] >= 0) dp[i][j][k] = min(dp[i][j][k], dp[i+1][j-1][k - a[i]] + b[i]);
            }
        }
    }

   
    long double ans = 1e18;

    
    for(int i = 0; i <= sm; i++){
        if(i && sm - i > 0&& sb > dp[1][l][i]) ans = min(ans, (dp[1][l][i]/(long double)i)*(sb-dp[1][l][i])/(long double)(sm - i));
        if(i && sm - i > 0&& sb > dp[1][n-l][i] && dp[1][n-l][i]) ans = min(ans, (dp[1][n-l][i]/(long double)i)*(sb-dp[1][n-l][i])/(long double)(sm - i));
            
        
    }

    cout << setprecision(3) << fixed << ans << "\n";
}