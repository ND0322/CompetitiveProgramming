#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1e6+5;
const int MOD = 1e9+7;

int pow(long long a, long long b){
    int ans = 1;
    while(b){
        if (b&1) ans = (ans*a) % MOD;
        b>>=1;
        a = (a*a) % MOD;
    }
    return ans;
}

long long n, m, dp[MAXN][2];

//last was blue or red or not?


int main(){
    cin >> n >> m;

    dp[m][0] = dp[m][1] = 1;

    for(int i = m-1; i >= 0; i--){
        dp[i][0] = (dp[i+1][0] + dp[i+1][1] * 2) % MOD;
        dp[i][1] = (dp[i+1][0] + dp[i+1][1]) % MOD;
    }


    cout << pow(dp[0][0], n) << "\n";
}