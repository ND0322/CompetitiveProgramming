#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define int long long

const int MAXN = 2e5+5;
const int MOD = 998244353;

int dp[MAXN][2][2];


/*
no 101
000
010
111
each ? only affects 3 things


*/

int32_t main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        string s; cin >> s;

        s = '.' + s;

        for(int i = 1; i <= n; i++){
            dp[i][0][0] = 0;
            dp[i][0][1] = 0;
            dp[i][1][0] = 0;
            dp[i][1][1] = 0;
        }

        dp[n+1][0][0] = 1;
        dp[n+1][1][0] = 1;
        dp[n+1][0][1] = 1;
        dp[n+1][1][1] = 1;


        for(int i = n; i >= 1; i--){
            for(int a = 0; a < 2; a++){
                for(int b = 0; b < 2; b++){
                    if(i < 3){
                        if(s[i] == '1' || s[i] == '?') dp[i][a][b] = dp[i+1][b][1];
                        if(s[i] == '0' || s[i] == '?') dp[i][a][b] = (dp[i][a][b] + dp[i+1][b][0]) % MOD;
                        continue;
                    }

                    if(s[i] == '1' || s[i] == '?'){
                        if(a != 1) dp[i][a][b] = (dp[i][a][b] + dp[i+1][b][1]) % MOD; 
                    } 

                    if(s[i] == '0' || s[i] == '?'){
                        if(a != 0) dp[i][a][b] = (dp[i][a][b] + dp[i+1][b][0]) % MOD; 
                    } 
                }
            }
        }

        cout << dp[1][0][0] << "\n";
    }
}