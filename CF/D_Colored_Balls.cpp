#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 5005;
const int MOD = 998244353;

#define int long long

int n, a[MAXN], dp[MAXN];

int32_t main(){
    cin >> n;

    for(int i = 1; i <= n; i++) cin >> a[i];

    sort(a+1,a+n+1);

    dp[0] = 1;
    long long ans = 0;
    for(int j = 1; j <= n; j++){
        for(int i = MAXN-1; i >= a[j]; i--){
            dp[i] = (dp[i]+dp[i-a[j]]) % MOD;

            if(i <= a[j]*2) ans = (ans + a[j] * dp[i-a[j]])%MOD;
            else ans = (ans+((i-1)/2+1) * dp[i-a[j]])%MOD;
        }
    }

    cout << ans << "\n";

    
    
}