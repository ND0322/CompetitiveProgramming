#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1e5+5;
const int MOD = 1e9+7;

int n, dp[MAXN][3][2];

string k;

//dp is current index, if we have 1, 10 or no 1 respectively, is there a digit less than k so far

int main(){
    cin >> k;

    n = k.size();

    k = '.' + k;

    dp[n+1][2][0] = 1;
    dp[n+1][2][1] = 1;

    for(int i = n; i >= 1;i--){
        for(int h = 0; h < 2; h++){

            dp[i][2][0] = 1;
            dp[i][2][1] = 1;
            for(int j = 0; j < 10; j++){
                if(i == 1 && j == 0) continue;
                if(h && k[i] - '0' < j) continue;
                if(i == 1 && h == 1) cout << j << "\n";
                if(j){
                    dp[i][0][h] = (dp[i][0][h] + dp[i+1][j == 1][h && (j == k[i] - '0')]) % MOD;
                    dp[i][1][h] = (dp[i][1][h] + dp[i+1][1][h && (j == k[i] - '0')]) % MOD;
                    dp[i][2][h] = (dp[i][2][h] + dp[i+1][2][h && (j == k[i] - '0')]) % MOD;

                }
                else{
                    dp[i][0][h] = (dp[i][0][h] + dp[i+1][0][h && (j == k[i] - '0')]) % MOD;
                    dp[i][1][h] = (dp[i][1][h] + dp[i+1][2][h && (j == k[i] - '0')]) % MOD;
                }
            }
        }   
    }

    cout << dp[1][0][1] << "\n";
    cout << dp[1][2][1] << "\n";






}