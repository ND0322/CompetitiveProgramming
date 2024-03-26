#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1e5+5;

int n, d[MAXN], w[MAXN];

long long dp[MAXN][2];

int main(){
    cin >> n;

    for(int i = 1; i <= n; i++) cin >> d[i] >> w[i];

    for(int i = n; i >= 1; i--){
        dp[i][0] = min(dp[i+1][0] + max(0, d[i] - w[i+1]), dp[i+1][1] + d[i]);
        dp[i][1] = min(dp[i+1][0] + max(0, d[i] - w[i+1] - w[i-1]), dp[i+1][1] + max(0, d[i] - w[i-1]));
    }

    cout << dp[1][0] << "\n";
}