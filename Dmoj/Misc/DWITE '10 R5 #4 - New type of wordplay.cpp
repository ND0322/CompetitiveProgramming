#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 155;

int dp[MAXN][MAXN];

int main() {

    int tt= 5;

    while(tt--){
        string s; cin >> s;
        int n = s.size();
        for(int i = 0; i < n; i++) dp[i][i] = 1;
            
        

        for(int i = n-1; i >= 0; i--){
            for(int j = i+1; j < n; j++){
                dp[i][j] = 1+dp[i+1][j];

                for(int k = i+1; k <= j; k++){

                    if(s[i] == s[k]) dp[i][j] = min(dp[i][j],dp[i+1][k] + dp[k+1][j]);
                
                    
                }
            }
        }

        cout << (dp[0][n-1] == n ? 'S' : 'U');
    }
    
}