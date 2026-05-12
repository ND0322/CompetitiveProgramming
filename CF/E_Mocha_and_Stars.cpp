#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MOD = 998244353;
const int MAXN = 1e5+5;

/*
let f(i) be the answer if no gcd constraints
dp[i] be answer if gcd is 1

dp[m] = f(m) - sum(dp[m/j]) for each j in set [2, m]

right half can be done with the coci sqrt idea I think (there are only sqrt big and small values)
*/

int n, m, dp[MAXN], f[MAXN][55], psa[MAXN][55];

pair<int,int> range[MAXN];

int main(){
    cin >> n >> m;

    for(int i = 1; i <= n; i++) cin >> range[i].first >> range[i].second;

    f[0][n+1] = 1;
    psa[0][n+1] = 1;
    for(int j = 1; j <= m+1; j++) psa[j][n+1] = psa[j-1][n+1] + f[j-1][n+1];
    for(int i = n; i >= 1; i--){
        for(int j = 0; j <= m; j++){
            if(range[i].first > j) continue;
            

            f[j][i] = psa[j - range[i].first+1][i+1] - psa[j - min(range[i].second, j)][i+1] ;
            //cout << i << " " << j << " " << j - range[i].first+1 << " " << j - min(range[i].second, j) << " " << f[j][i] << "\n";
        }

        psa[0][i] = f[0][i];
        for(int j = 1; j <= m+1; j++) psa[j][i] = psa[j-1][i] + f[j-1][i];
    }

    
    
    for(int i = 2; i <= m; i++){
        dp[i] = psa[i+1][1];

        for(int j = 2; j <= m; j++) dp[i] -= dp[i/j];
    }

    

    cout << dp[m] << "\n";
}