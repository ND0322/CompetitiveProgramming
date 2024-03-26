#include <bits/stdc++.h>
#include <iostream>

using namespace std;



const int MAXN = 105;

int n;
long long a[MAXN], k[2], c[2], l[2], dp[MAXN][1005];


int main(){
    cin >> n;

    for(int i = 0; i < n; i++) cin >> a[i];

    cin >> l[0] >> c[0] >> k[0];
    cin >> l[1] >> c[1] >> k[1];

    memset(dp, 0x3f, sizeof(dp));

    fill(dp[n], dp[n] + k[0]+1, 0);


    for(int i = n-1; i >= 0; i--){
        for(int j = k[0]; j >= 0; j--){
            for(int p = 0; p <= j; p++){
                dp[i][j] = min(dp[i][j], dp[i+1][j-p] + (max((long long)0, a[i] - p*l[0]) + l[1] - 1) / l[1]);
            }
        }
    }



    long long ans = 1e18;

    for(int i = 0; i <= k[0]; i++){
        //cout << dp[0][i] << "\n";
        //cout << i * c[0] << " " << dp[0][i] * c[1] << "\n";
        if(dp[0][i] <= k[1] ) ans = min(ans, (long long)i * c[0] + (long long)dp[0][i] * c[1]);
        
    }

    cout << (ans == 1e18 ? -1 : ans) << "\n";
}