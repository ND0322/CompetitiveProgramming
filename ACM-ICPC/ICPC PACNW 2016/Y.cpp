#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 55;

int n, a[MAXN], dp[MAXN][2];

int main(){
    cin >> n;

    for(int i = 0; i < n; i++) cin >> a[i];

    for(int i = n -1; i >= 0; i--){
        for(int j = i+1; j < n; j++){
            if(a[j] > a[i]) dp[i][0] = max(dp[i][0], dp[j][1]+1);
            if(a[i] > a[j]) dp[i][1] = max(dp[i][1], dp[j][0]+1);
        }

        dp[i][0] = max(dp[i][0], dp[n][0]+1);
        dp[i][1] = max(dp[i][1], dp[n][0]+1);
    }

    int ans = 0;

    for(int i = 0; i < n; i++){
        ans = max({ans, dp[i][0], dp[i][1]});
    }

    cout << ans << "\n";
}