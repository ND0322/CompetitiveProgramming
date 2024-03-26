#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 505;
const int MOD = 1e9+7;

#define int long long

int n, dp[MAXN][MAXN], a[MAXN], b[MAXN];

//store the main splits and do some sh in between

int solve(int i, int j){
    if(i == n+1 && j == n+1) return 1;
    if(i == n+1 || j == n+1) return 0;

    if(dp[i][j] == -1){
        dp[i][j] = 0;

        long long sum = 0;
        for(int l = i; l <= n; l++){
            sum += a[l];

            long long res = 0;
            for(int p = j; p <= n; p++){
                res += b[p];

                if(sum/(double)(l-i+1) <= res/(double)(p-j+1)) dp[i][j] = (dp[i][j] + solve(l+1,p+1)) % MOD;
            }
        }
    }

    return dp[i][j];
}

int32_t main(){
    cin >> n;

    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int j = 1; j <= n; j++) cin >> b[j];

    memset(dp, -1, sizeof(dp));

    cout << solve(1,1) << "\n";

}