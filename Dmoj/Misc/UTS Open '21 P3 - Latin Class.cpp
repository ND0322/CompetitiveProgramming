#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define int long long

const int MAXN = 1e5+5;
const int MOD = 1e9+7;

int n, dp[MAXN], a[MAXN], pos[MAXN], suf1[MAXN], suf2[MAXN];

bool mx[MAXN];

int32_t main(){
    cin >> n;

    int m = 1;
    int pref = 0;

    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        if(x >= pref){
            pos[m] = i;
            pref = x;
            m++;
        }
    }

    suf1[m] = 1;
    dp[m] = 1;
    for(int i = m-1; i >= 1; i--){
        dp[i] = suf1[i+1];

        suf1[i] = (suf1[i+1] + (dp[i] * (pos[i] - pos[i-1])) % MOD) % MOD;
    }

    cout << dp[1] << "\n";
    

    


}