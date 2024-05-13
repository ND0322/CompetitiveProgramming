#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1e7+5;
const int MOD = 1e9+7;

int n;

int dp[MAXN][4];

/*
0 is D
1 is A
2 is B
3 is C
*/

int main(){
    cin >> n;

    dp[0][0] = 1;


    for(int i = 1; i <= n; i++){
        dp[i][0] = ((dp[i-1][1] + dp[i-1][2]) % MOD + dp[i-1][3]) % MOD;
        dp[i][1] = ((dp[i-1][0] + dp[i-1][2]) % MOD + dp[i-1][3]) % MOD;
        dp[i][2] = ((dp[i-1][1] + dp[i-1][0]) % MOD + dp[i-1][3]) % MOD;
        dp[i][3] = ((dp[i-1][1] + dp[i-1][2]) % MOD + dp[i-1][0]) % MOD;
    }

    cout << dp[n][0] << "\n";

}