#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 305;

int n, k, dp[MAXN][MAXN];

string s;

int main(){
    cin >> s;

    n = s.size();

    cin >> k;


    for(int i = 0; i < n; i++) dp[i][i] = 1;

    for(int i = n-1; i >= 0; i--){
        for(int j = i+1; j < n; j++){
            dp[i][j] = 1 + dp[i+1][j];
            if(s[i] != 'o') continue;
            for(int l = i+1; l <= j; l++){
                if(!dp[i+1][l-1] && s[l] == 'f') dp[i][j] = min(dp[i][j], max(dp[l+1][j]-k, 0));
            }
            
        }
    }

    cout << dp[0][n-1] << "\n";
}