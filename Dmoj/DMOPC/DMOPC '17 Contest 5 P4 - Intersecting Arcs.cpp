#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 105;


int main(){
    cin >> n >> k;



    
    dp[n+1][0][0] = 1;
    for(int i = n; i >= 1; i--){
        for(int j = 0; j < i; j++){
            for(int l = 0; l <= k; l++){
                dp[i][j][l] = dp[i+1][j][l] + dp[i+1][j+1][l];

                if(j) for(int z = 0; z <= min(j, l); z++) dp[i][j][l] += dp[i+1][j-1][l-z];
                

                cout << i << " " << j << " " << l << " " << dp[i][j][l] << "\n";
            }
        }
    }
    
    
    

    

    //cout << dp[1][0][k] << "\n";
    
}