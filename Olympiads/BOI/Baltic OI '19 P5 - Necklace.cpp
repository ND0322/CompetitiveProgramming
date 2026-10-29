#include <bits/stdc++.h>
#include <iostream>

using namespace std;


const int MAXN = 3005;

int n, m, dp[MAXN][MAXN<<1][2];


//n^2 

int main(){
    string s,t; cin >> s >> t;


    n = s.size();

    s = '.' + s;

    m = t.size();

    t = '.' + t;

    for(int i = 1; i <= m; i++) t += t[i];


    for(int i = n; i >= 1; i--){
        for(int j = 2*m; j >= 1; j--){
            dp[i][j][0] = dp[i+1][j][0];

            dp[i][j][0] = max(dp[i][j][0], dp[i][j+1][0]);

            //if on

            if(s[i] != s[j]) dp[i][j][1] = 0;
            else dp[i][j][1] = dp[i+1][j+1][1] + 1;

            //turn on

            dp[i][j][0] = max(dp[i][j][0], dp[i][j][1]);

            cout << i << " " << j << " " << dp[i][j][0] << " " << dp[i][j][1] << "\n";
        }
    }

    cout << dp[1][1][0] << "\n";


}