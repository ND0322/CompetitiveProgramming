#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2e5+5;
const int MOD = 998244353;
//simple dp

int n, m;

double dp[MAXN], p[MAXN], q[MAXN];

vector<pair<int,int>> rs[MAXN];

int quickpow(int a, int b){
    int ans = 1;
    while(b >= 1){
        if(b & 1){
            ans = (ans * b) % MOD;
            b--;
        }
        else{
            a = (a*a) % MOD;
            b >>=1;
        }
    }

    return ans;
}

int main(){
    cin >> n >> m;

    double ans = 1;
    for(int i = 1; i <= n; i++){
        int l,r; cin >> l >> r;

        rs[l].push_back({r, i});
        cin >> p[i] >> q[i];

        ans *= (q[i] - p[i]) / q[i];
    }


    dp[m+1] = 1;
    dp[m] = 1;
    for(int i = m-1; i >= 0; i--){

        //val * 1/q-p * p
        for(auto [r,j] : rs[i+1]) dp[i] += dp[r] * p[j] / (q[j] - p[j]);
    }

    /*
    
    1/9

    2/3 + 1/6
    */

    cout << dp[3] << "\n";

    cout << ans * dp[0] << "\n";
}
