#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 505;
const int MOD = 1e9+7;

int n, a,b, k, dp[MAXN][MAXN][2];

int main(){
    cin >> a >> b >> k;

    dp[0][0][0] = 1;
    dp[0][0][1] = 1; 

    for(int i = 0; i <= a; i++){
        for(int j = 0; j <= b; j++){
            if(!i && !j) continue;

            if(!i && j > k) continue;
            if(!j && i > k) continue;
            //last placed was 0
            if(i) for(int l = 1; l <= min(i, k); l++) dp[i][j][0] += dp[i-l][j][1];
            if(j) for(int l = 1; l <= min(j,k); l++) dp[i][j][1] += dp[i][j-l][0];

        }
    }

    //1 next to place is 1p 
    //1 0 0 1 0 0
    //brute some length of 0s greater than k and add some 1s in between
    //less than k doesnt need 1s
    cout << dp[4][1][0] << "\n";
    cout << dp[a][b][0] << "\n";
    cout << dp[a][b][1] << "\n";
    cout << dp[a][b][0] + dp[a][b][1] << "\n";

}