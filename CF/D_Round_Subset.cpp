#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 205;

int n, k, dp[MAXN][MAXN*26][2];

long long a[MAXN];

int main(){
    cin >> n >> k;

    for(int i = 1; i <= n; i++) cin >> a[i];

    for(int i = 0; i <= k; i++){
        for(int j = 0; j <= n*26; j++) dp[i][j][1] = -1e9;
    }

    dp[0][0][1] = 0;

    for(int i = n; i >= 1; i--){
        int cnt = 0;
        int v = 0;

        long long cur = a[i];

        while(!(cur%5)){
            cnt++;
            cur/=5;
        }

        cur = a[i];

        while(!(cur&1)){
            v++;
            cur>>=1;
        }
        for(int j = 0; j <= k; j++){
            for(int l = 0; l <= n*26; l++){
                dp[j][l][0] = dp[j][l][1];

                if(j && l - cnt >= 0) dp[j][l][0] = max(dp[j][l][0], dp[j-1][l-cnt][1] + v);
            }
        }

        for(int j = 0; j <= k; j++){
            for(int l = 0; l <= n*26; l++){
                dp[j][l][1] = dp[j][l][0];
                dp[j][l][0] = 0;
            }
        }

        
    }

    int ans = 0;

    for(int i = 1; i <= n*26; i++) ans = max(ans, min(i,dp[k][i][1]));
    cout << ans << "\n";

}