#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2e5+5;

#define int long long

int n, dp[MAXN][2];

//0 is not cut

//lrr

pair<int,int> a[MAXN];

int32_t main(){
    cin >> n;

    for(int i = 1; i <= n; i++) cin >> a[i].first >> a[i].second;

    sort(a+1,a+n+1);

    for(int i = n; i >= 1; i--){
        if(i == n){
            dp[i][0] = 1;
            continue;
        }

        //dont touch
        dp[i][0] = dp[i][1] = dp[i+1][0];
        //knock right
        if(a[i].second + a[i].first < a[i+1].first) dp[i][0] = max(dp[i][0],dp[i+1][0] + 1);
        if(a[i+1].first - a[i+1].second > a[i].first){
            dp[i][0] = max(dp[i][0],dp[i+1][1] + 1);
            dp[i][1] = max(dp[i][1],dp[i+1][1] + 1);
        }

        //both
        if(a[i+1].first - a[i+1].second > a[i].first + a[i].second) dp[i][0] = max(dp[i][0], dp[i+1][1] + 2);
    }

    cout << max(dp[1][0], dp[1][1] + 1) << "\n";
}