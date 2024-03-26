#include <bits/stdc++.h>
#include <iostream>

#define int long long

using namespace std;

const int MAXN = 255;

int n, cap, a[MAXN], w[MAXN];

double dp[MAXN][1005];

//convert sum of a / sum of w >= max
//sum of a >= max * sum of w
//sum of a - sum of w*max >= 0
//sum of w*max - a <= 0
//for some max

bool can(long long m){

    double x = m/1000.0;

    fill(dp[n], dp[n] + cap+1, 1e18);
    dp[n][cap] = 0;
    for(int i = n-1; i >= 0; i--){
        for(int j = 0; j <= cap; j++) dp[i][j] = min(dp[i+1][j], dp[i+1][min(cap, j + w[i])] + x * w[i] - a[i]);
        
    }
    return dp[0][0] <= 0;
}

int32_t main(){

    freopen("talent.in", "r", stdin);
    freopen("talent.out", "w", stdout);
    cin >> n >> cap;

    for(int i = 0; i < n; i++) cin >> w[i] >> a[i];

    long long lo = 0;
    long long hi = 1e18;
    long long ans = -1;

   
    while(lo <= hi){
        long long mid = (lo+hi)>>1;

        if(can(mid)){
            ans = mid;
            lo = mid+1;
        }
        else hi = mid-1;
    }

    cout << ans << "\n";
}