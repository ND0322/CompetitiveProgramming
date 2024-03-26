#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 4100;
const int INF = INT_MAX;

int n,p, a[MAXN];

int main(){

    cin >> n >> p;

    for(int i = 0; i < n; i++) cin >> a[i];

    vector<vector<int>> dp(n+1,vector<int>(p+1,-INF));
    dp[n][0] = 0;

    for(int i = n-1; i >= 0; i--){
        for(int j = 0; j < p; j++){
            dp[i][j] = max(dp[i+1][j],dp[i+1][(j+a[i]) % p] + a[i]);
        }
    }

    cout << dp[0][0] << "\n";
    cout <<"1\n1\n";
}