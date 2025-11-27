#include <bits/stdc++.h>
#include <iostream>

#pragma GCC target ("avx2")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")

using namespace std;

const int MOD = 1e9+7;



bool dp[1<<20][25][2];

long long quickpow(long long a, int b){
    long long res = 1;
    while(b > 0){
        if(b&1) res = (res * a) % MOD;
        a = (a*a) % MOD;
        b >>=1;
    }
    return res;
}
int main(){
    cin.tie(NULL) -> ios_base::sync_with_stdio(0);
    int tt; cin >> tt;

    for(int i =0; i < 1<<20; i++) dp[i][1][0] = dp[i][1][1] = i&1;

    while(tt--){
        int n,m; cin >> n >> m;        

        int k; cin >> k;
        vector<int> good(k);

        for(int i = 0; i < k; i++) cin >> good[i];

        if(m == 1){
            cout << "1\n";
            continue;
        }

        vector<int> cnt(n+1);

        for(int i = 0; i < 1<<n; i++){
            for(int j = 2; j <= n; j++){
            
                dp[i][j][1] = 1; 
                dp[i][j][0] = 0;
                for(int p : good){
                    if(p > j) break;

                    int nxt =(((1<<(p-1))-1) & i) + (((((1<<j) - 1) ^ (((1<<p)-1))) & i) >> 1);
                   
                    dp[i][j][0] |= dp[nxt][j-1][1];
                    dp[i][j][1] &= dp[nxt][j-1][0];
                }
            }

            cnt[__builtin_popcount(i)]+=dp[i][n][0];


        }

        long long ans = 0;
    

        //let dp denote such that 0 represents a number less than i
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                ans = (ans + ((quickpow(i-1, n-j) * quickpow(m-i+1, j)) % MOD * cnt[j]) % MOD) % MOD;
            }
        }

        cout << ans << "\n";


    }
}