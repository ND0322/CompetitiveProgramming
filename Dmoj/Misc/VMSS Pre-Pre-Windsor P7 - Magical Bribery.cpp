#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1005;

int n,dp[MAXN],a[MAXN];

int main(){
    cin >> n;

    for(int i = 1; i <= n; i++) cin >> a[i];

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            dp[i] = max(dp[i],dp[i-j] + a[j]);
        }
    }

    cout << dp[n] << "\n";
}