#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define int long long

const int MAXN = 2e5+5;
const int MOD = 998244353;

//simple dp

int dp[MAXN], p[MAXN], q[MAXN], n, m;

vector<pair<int,int>> rs[MAXN];

int quickpow(int a, int b){
    int ans = 1;
    while(b >= 1){
        if(b & 1){
            ans = (ans * a) % MOD;
            b--;
        }
        else{
            a = (a*a) % MOD;
            b >>=1;
        }
    }

    return ans;
}

int32_t main(){
    cin >> n >> m;

    int ans = 1;
    for(int i = 1; i <= n; i++){
        int l,r; cin >> l >> r;

        rs[l].push_back({r, i});
        cin >> p[i] >> q[i];
 
        ans = (ans * (q[i] - p[i] + MOD) % MOD) % MOD;
        ans = (ans * quickpow(q[i], MOD-2)) % MOD;
    }

    dp[m+1] = 1;
    dp[m] = 1;
    for(int i = m-1; i >= 0; i--){

        //val * 1/q-p * p
        for(auto [r,j] : rs[i+1]) dp[i] = (dp[i] + (((((quickpow((q[j] - p[j] + MOD) % MOD, MOD-2)) % MOD) * p[j]) % MOD) * dp[r]) % MOD) % MOD;
    }
    cout << (ans * dp[0]) % MOD << "\n";
}
