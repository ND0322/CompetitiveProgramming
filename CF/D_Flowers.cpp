#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1e5+5;
const int MOD = 1e9+7;
int n, k, q;

long long dp[MAXN],psa[MAXN];

int main(){
    cin >> q >> k;

    dp[0] = 1;
    for(int i = 1; i < MAXN; i++){
       
        dp[i] = (dp[i-1] + (i >= k ? dp[i-k]: 0))%MOD;
        psa[i] = (dp[i] + psa[i-1])%MOD;
    }

   
    while(q--){
        int l, r; cin >> l >> r;

        cout << (psa[r] - psa[l-1]+MOD)%MOD << "\n";
    }

    


}