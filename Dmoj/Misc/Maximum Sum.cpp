#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1e5+5;

int n, a[MAXN] ,dp[MAXN];

int main(){
    cin >> n;

    for(int i = 1; i <= n; i++) cin >> a[i];

    for(int i = n; i >= 1; i--) dp[i] = max(dp[i+1], dp[i+2] + a[i]);
    cout << dp[1] << "\n";
}