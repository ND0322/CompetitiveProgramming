#include <bits/stdc++.h>
#include <iostream>


using namespace std;

const int MAXN = 5005;
const int MOD = 1e9 + 7;

//start by placing n
//cout number of possible subarrays
//state is n and min element
//min will always be at the left or right end


int n,k;

long long dp[MAXN][MAXN], temp[MAXN];

int main(){
    cin.tie(NULL) -> ios_base::sync_with_stdio(0);
    cin >> n >> k;

    dp[2][n-1] = 2;
    for(int i = 3; i <= n; i++){

        fill(temp, temp + n, 0);
        temp[n-1] = dp[i-1][n-1];
        //temp count even dp starting from j

        for(int j = n-2; j >= 1; j--) temp[j] = (dp[i-1][j] + temp[j+2]) % MOD;
            //for(int l = 2; l + j -1 < n; l+=2) dp[i][j] = (dp[i][j] + dp[i-1][l+j-1]) % MOD;
            //for(int l = 0; l + j + i -1 < n; l+=2) dp[i][j] = (dp[i][j] + dp[i-1][l+j+i-1]) % MOD;
        for(int j = n-2; j >= 1; j--){
            if(i + j <= n) dp[i][j] = temp[i+j-1];
            dp[i][j] = (dp[i][j] + temp[j+1]) % MOD;
        }
    }

    long long ans = 0;

    for(int i = 2; i <= min(n,k); i++){
        for(int j = 1; j < n; j++){
            ans = (ans + (dp[i][j] * (k-i + 1)) % MOD) % MOD;
        }
    }

    cout << ans << "\n";
}