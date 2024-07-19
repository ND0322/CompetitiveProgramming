#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 5005;

int n, dp[MAXN][MAXN<<1][2];

string s;

int main(){
    s = '_';

    string c; cin >> c;
    s += c;

    n = c.size();

    dp[n][n][0] = 1;
 
    for(int i = n-1; i >= 0; i--){
        for(int j = 0; j <= 2*n; j++){
            dp[i][j][1] = dp[i+1][j][1];

            if(j && (s[i+1] == '(' || s[i+1] == '?')){
                dp[i][j][0] += dp[i+1][j+1][0];
                dp[i][j][1] += dp[i+1][j+1][0];
            }
            if(j <= 2*n && (s[i+1] == ')' || s[i+1] == '?')){
                dp[i][j][0] += dp[i+1][j-1][0];
                dp[i][j][1] += dp[i+1][j-1][0];
            }
        }

        dp[i][n][0]++;

        for(int j = 0; j <= 2*n; j++) cout << i << " " << j << " " << dp[i][j][0] << "\n";
    }

    cout << dp[0][n][1] << "\n";

    //1 + 1 + 1 + 
}