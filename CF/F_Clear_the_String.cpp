#include <bits/stdc++.h>
#include <iostream> 

using namespace std;

const int MAXN = 505;

int n,dp[MAXN][MAXN];

string s;

int main(){
    cin >> n;

    cin >> s;

    for(int i = n-1; i >= 0; i--){
        for(int j = i+1; j < n; i++){
            dp[i][j] = 1 + dp[i+1][j];

            cout << i << " " << j << endl;

            cout << s[i] << " " << s[i+1] << endl;


            for(int c = i+1; c <= j; i++){
                if(s[c] == s[i]){
                    dp[i][j] = min(dp[i][j],dp[i+1][c-1] + dp[c][j]);
                }
            }
        }

        
    }

    cout << dp[0][n-1] << "\n";
}