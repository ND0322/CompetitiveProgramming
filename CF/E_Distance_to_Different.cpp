#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2e5+5;
const int MOD = 998244353;

int n, k;

long long dp[MAXN][15], ssa[MAXN][15];

//prefix will look like x-1 x-2 x-3 ... 2 1
//chunks of the middle will be palindromes of the form 1 2 3 ... x-1 x-1 ... 3 2 1 for even and one x for odd
//we need at least k chunks
//2 causes problems cause it looks the same as two ones put together so we only put it at the front or back

int main(){
    cin >> n >> k;

    dp[n+1][0] = 1;
    ssa[n+1][0] = 1;

    for(int i = n; i >= 1; i--){
        for(int j = 0; j <= k; j++){

            dp[i][j] = ssa[i+1][max(j-1, 0)];         

            if(i != 1 && i != n-1) dp[i][j] = (dp[i][j] - dp[i+2][max(j-1,0)] + MOD) % MOD;
        }

        for(int j = 0; j <= k; j++) ssa[i][j] = (ssa[i+1][j] + dp[i][j]) % MOD;
    
    }

    cout << dp[1][k] << "\n";
}