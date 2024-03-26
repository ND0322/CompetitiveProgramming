#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1e6+5;
const int MOD = 1e9+7;

#define int long long

//number of paintings that have at least one length k chunk cause the last one will always cover length k

int n,k,m, dp[MAXN], psa[MAXN], pre[MAXN];

int32_t main(){
    freopen("spainting.in", "r", stdin);
    freopen("spainting.out", "w", stdout);
    cin >> n >> m >> k;

    pre[0] = 1;
    for(int i = 1; i <= n; i++) pre[i] = (pre[i-1] * m)%MOD;
    
    for(int i = 1; i <= n; i++){
        if(i < k) dp[i] = pre[i];
        else dp[i] = (((psa[i-1] - psa[max(0LL, i-k)] + MOD) % MOD) * (m-1)) % MOD;
        
        psa[i] = (dp[i] + psa[i-1]) % MOD;
    }

    cout << (pre[n] - dp[n] + MOD) % MOD<< "\n";


}

