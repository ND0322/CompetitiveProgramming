#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2e5+5;
const int MOD = 998244353;

int n, a[MAXN], dp[MAXN][3][3][2];

//i, parity of last 2 numbers

int main(){
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> a[i];
        a[i] &= 1;
    }

    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++) dp[n][i][j][1] = 1;
    }

    
    for(int i = n-1; i >= 0; i--){
        for(int j = 0; j <= 2; j++){
            for(int k = 0; k <= 2; k++){
                for(int l = 0; l < 2; l++){
                    dp[i][j][k][l] = dp[i+1][j][k][l];
                    
                    if(j == 2 || k == 2 || (j+k+a[i])%2 == 0) dp[i][j][k][l] = (dp[i][j][k][l] + dp[i+1][k][a[i]][l | (j != 2 && k != 2)]) % MOD;
                }
            
                
                
                
            }
        }
    }

    cout << dp[0][2][2][0] << "\n";
    

    
}

