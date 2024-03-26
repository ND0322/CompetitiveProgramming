#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1e4+5;

int n, a[MAXN];

double dp[MAXN];

int main(){
    cin >> n;

    for(int i = 0; i < n; i++) cin >> a[i];

    for(int i = n-1; i >= 0; i--){
        dp[i] = min({dp[i+1] + a[i], dp[i+2] + max(a[i],a[i+1]) + min(a[i],a[i+1])/2.0, dp[i+3] + a[i] + a[i+1] + a[i+2] - min({a[i],a[i+1],a[i+2]})});
    }

    cout << setprecision(1) << fixed << dp[0] << "\n";
}

