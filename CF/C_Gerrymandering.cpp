#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1e5+5;

int n, a[MAXN][2], dp[MAXN][3];

int main(){
    int tt; cin >> tt;

    while(tt--){
        cin >> n;

        for(int i = 1; i <= n; i++){
            char c; cin >> c;
            a[i][0] = (c == 'A');
        }
        for(int i = 1; i <= n; i++){
            char c; cin >> c;
            a[i][1] = (c == 'A');
        }

        for(int i = 1; i <= n+4; i++){
            dp[i][0] = dp[i][1] = dp[i][2] = -1e9;
        }
        dp[n+1][2] = 0;
        for(int i = n; i >= 1; i--){
            
            dp[i][0] = max(dp[i+2][2] + (a[i][1] + a[i+1][0] + a[i+1][1] >= 2), dp[i+3][0] + (a[i][1] + a[i+1][1] + a[i+2][1] >= 2) + (a[i+1][0] + a[i+2][0] + a[i+3][0] >= 2));
            dp[i][1] = max(dp[i+2][2] + (a[i][0] + a[i+1][0] + a[i+1][1] >= 2), dp[i+3][1] + (a[i][0] + a[i+1][0] + a[i+2][0] >= 2) + (a[i+1][1] + a[i+2][1] + a[i+3][1] >= 2)); 
            dp[i][2] = max({dp[i+1][0] + (a[i][0] + a[i][1] + a[i+1][0] >= 2), dp[i+1][1] + (a[i][0] + a[i][1] + a[i+1][1] >= 2), dp[i+3][2] + (a[i][0] + a[i+1][0] + a[i+2][0] >= 2) + (a[i][1] + a[i+1][1] + a[i+2][1] >= 2)});  

        }

        cout << dp[1][2] << "\n";

    }
}

/*
* * * 
  * * * 
 
*/