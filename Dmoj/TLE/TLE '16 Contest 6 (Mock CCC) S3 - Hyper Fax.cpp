#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2005;

#define int long long

int n, dp[MAXN][MAXN][2], psa[MAXN];

pair<int,int> a[MAXN];

//l, r, side

int32_t main(){
    cin >> n;

    for(int i = 1; i <= n; i++) cin >> a[i].first >> a[i].second;

    sort(a+1,a+n+1);

    for(int i = 1; i <= n; i++){
        psa[i] = psa[i-1] + a[i].second;
        if(!a[i].first){
            dp[i][i][0] = a[i].second;
            dp[i][i][1] = a[i].second;
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++) dp[i][j][0] = dp[i][j][1] = -1e18;
    }

    for(int i = n; i >= 1; i--){
        for(int j = i; j <= n; j++){
            //expand l to the left
            //l+1 -> l
            if(abs(a[i].first - a[i+1].first) <= dp[i+1][j][0]) dp[i][j][0] = max(dp[i][j][0], dp[i+1][j][0] + a[i].second - abs(a[i].first - a[i+1].second));
            //r -> l
            if(abs(a[i].first - a[j].first) <= dp[i+1][j][1]) dp[i][j][0] = max(dp[i][j][0], dp[i+1][j][1] + a[i].second - abs(a[i].first - a[j].first));

            //expand r to the right

            //r-1 -> r
            if(abs(a[j].first - a[j-1].first) <= dp[i][j-1][1]) dp[i][j][1] = max(dp[i][j][1], dp[i][j-1][1] + a[j].second - abs(a[j].first - a[j-1].first));
            //l -> r
            if(abs(a[i].first - a[j].first) <= dp[i][j-1][0]) dp[i][j][1] = max(dp[i][j][1], dp[i][j-1][0] + a[j].second - abs(a[i].first - a[j].first));
        }
    }

    int ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j++){
            if(dp[i][j][0] >= 0 || dp[i][j][1] >= 0) ans = max(ans, psa[j] - psa[i-1]);
                
            
        }
    }

    cout << ans << "\n";
}