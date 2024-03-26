#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 105;

int a[MAXN],n,f;

long long dp[MAXN][MAXN][5005],t;

int main(){
    cin >> n >> f >> t;

    for(int i = 0; i < n; i++){
        cin >> a[i];
    } 

   

 

    for(int i = n-1; i >= 0; i--){
        for(int j = f-1; j >= 0; j--){

            if(i < f) dp[i][j][0] = dp[i+1][j+1][0] + a[i];

            for(int k = 1; k <= (n*n)/2; k++){

                dp[i][j][k] = dp[i+1][j][k];

                

                if(k-(i-j) >= 0) dp[i][j][k] = max(dp[i][j][k],dp[i+1][j+1][k-(i-j)] + a[i]);
            }

            
            
        }
    }

    //cout << dp[0][0][1] << "\n";
    //cout << dp[1][1][1] << "\n";

    //cout << dp[0][0][3] << "\n";
    //cout << dp[1][1][3] << "\n";

    int ans = -1;

    for(int i = 0; i <= (n*n)/2; i++){
        if(dp[0][0][i] >= t){
            ans = i;
            break;
        } 
    }

    if(ans == -1)cout << "NO\n";
    else cout << ans << "\n";
}