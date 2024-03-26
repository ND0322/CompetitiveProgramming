#include <bits/stdc++.h>
#include <iostream>

using namespace std;


const int MAXN = 1e5+5;

int n, a[MAXN], b[MAXN], c[MAXN], dp[MAXN][2][2][2];

int solve(int i, bool one, bool two, bool three){
    if(i >= n) return 0;
    if(!one && !two && !three) return 0;

    if(dp[i][one][two][three] == -1){
        dp[i][one][two][three] = solve(i+1, one,two,three);

        if(one) dp[i][one][two][three] = max(dp[i][one][two][three], solve(i+1, one-1, two,three) + a[i]);
        if(two) dp[i][one][two][three] = max(dp[i][one][two][three], solve(i+1, one, two-1,three) + b[i]);
        if(three) dp[i][one][two][three] = max(dp[i][one][two][three], solve(i+1, one, two,three-1) + c[i]);
    }
    return dp[i][one][two][three];
    
}

int main(){
    int tt; cin >> tt;

    while(tt--){
        cin >> n;

        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++) cin >> b[i];
        for(int i = 0; i < n; i++) cin >> c[i];

        //memset(dp,-1,sizeof(dp));

        memset(dp,0,sizeof(dp));

        
        dp[n][1][0][0] = -1e9;
        dp[n][1][1][0] = -1e9;
        dp[n][0][1][0] = -1e9;
        dp[n][0][0][1] = -1e9;
        dp[n][0][1][1] = -1e9;
        dp[n][0][0][0] = -1e9;

        for(int i = n-1; i >= 0; i--){
            for(int j = 0; j <= 1; j++){
                for(int k = 0; k <= 1; k++){
                    for(int l = 0; l <= 1; l++){
                        dp[i][j][k][l] = dp[i+1][j][k][l];
                        if(!j) dp[i][j][k][l] = max(dp[i][j][k][l], dp[i+1][1][k][l] + a[i]);
                        if(!k) dp[i][j][k][l] = max(dp[i][j][k][l], dp[i+1][j][1][l] + b[i]);
                        if(!l) dp[i][j][k][l] = max(dp[i][j][k][l], dp[i+1][j][k][1] + c[i]);
                    }
                }
            }
        }

        cout << dp[0][0][0][0] << "\n";
        

       //cout << solve(0,1,1,1) << "\n";

        
    }
}

