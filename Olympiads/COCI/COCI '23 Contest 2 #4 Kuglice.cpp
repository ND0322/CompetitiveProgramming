#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 3005;

int n, dp[MAXN][MAXN], a[MAXN];

bool phave[MAXN][MAXN], shave[MAXN][MAXN];

int main(){
    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> a[i];
        phave[i][a[i]] = 1;

        for(int j = 1; j <= n; j++) phave[i][j] |= phave[i-1][j];
    }

    for(int i = n; i >= 1; i--){
        shave[i][a[i]] = 1;

        for(int j = 1; j <= n; j++) shave[i][j] |= shave[i+1][j];
    }

    bool ans = 0;

    for(int i = 1; i <= n; i++) dp[i][i] = (!phave[i-1][a[i]]) & (!shave[i+1][a[i]]);
    for(int i = n; i >= 1; i--){
        for(int j = i+1; j <= n; j++){
            int opt1 = ((!phave[i-1][a[i]]) & (!shave[j+1][a[i]])) + min(dp[i+2][j], dp[i+1][j-1]);
            int opt2 = ((!phave[i-1][a[j]]) & (!shave[j+1][a[j]])) + min(dp[i+1][j-1], dp[i][j-2]);

           
            if(opt1 > opt2) ans = 1;
            else ans = 0;
            
            dp[i][j] = max(opt1, opt2);
            
        }
    }

    cout << dp[1][n] << ":";
    if(ans) cout << dp[2][n] << "\n";
    else cout << dp[1][n-1] << "\n";


}