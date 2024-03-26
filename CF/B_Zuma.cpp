#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int dp[505][505],arr[505];

int main(){
    int n; cin >> n;

    for(int i =0; i < n; i++){
        cin >> arr[i];
        dp[i][i] = 1;
    }

    for(int i = n-1; i >= 0; i--){
        for(int j = i+1; j < n; j++){
            dp[i][j] = dp[i+1][j] + 1;

            for(int k = i+2; k <= j; k++){
                if(arr[i] == arr[k]){
                    dp[i][j] = min(dp[i][j],dp[i+1][k-1] + dp[k+1][j]);
                }
            }

            if(arr[i] == arr[i+1]){
                dp[i][j] = min(dp[i][j], 1+dp[i+2][j]);
            }

        }

    }

    cout << dp[0][n-1] << endl;
}