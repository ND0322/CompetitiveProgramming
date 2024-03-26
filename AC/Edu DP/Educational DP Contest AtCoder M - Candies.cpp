#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 105;
const int MOD = 1e9+7;

int n, a[MAXN], k, dp[MAXN][100005], psa[100005];

int main(){
    cin >> n >> k;

    for(int i = 1; i <= n; i++) cin >> a[i];

    dp[n+1][0] = 1;

    for(int i = n; i>= 1; i--){
        psa[0] = dp[i+1][0];

        for(int j = 1; j <= k; j++) psa[j] = psa[j-1] + dp[i+1][j];
        for(int j = 0; j <= k; j++) dp[i][j] = psa[j] - (j - a[i] > 0 ? psa[j-a[i]-1] : 0);
            

        
    }

    cout << dp[1][k] << "\n";
    cout << psa[k] << "\n";



    
}