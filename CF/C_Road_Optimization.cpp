#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define int long long

const int MAXN = 505;

int n,l,k, dp[MAXN][MAXN], pos[MAXN], a[MAXN];

//really easy dp

int32_t main(){
    cin >> n >> l >> k;

    for(int i = 1; i <= n; i++) cin >> pos[i];
    for(int i = 1; i <= n; i++) cin >> a[i];

    pos[n+1] = l;

    for(int i = n; i >= 1; i--){
        for(int j = 0; j <= k; j++){
            dp[i][j] = dp[i+1][j] + (pos[i+1] - pos[i]) * a[i];

            int cnt = 1;

            for(int nxt = i+2; nxt <= n+1; nxt++){
                if(j - cnt < 0) break;
                dp[i][j] = min(dp[i][j], dp[nxt][j-cnt] + (pos[nxt] - pos[i]) * a[i]);
                cnt++;
            }
        }
    }

    cout << dp[1][k] << "\n";

}