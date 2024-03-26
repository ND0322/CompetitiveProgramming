#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define int long long

const int MAXN = 3005;

int n, dp[MAXN][MAXN], a[MAXN];



int32_t main(){
    cin.tie(NULL) -> ios_base::sync_with_stdio(0);
    cin >> n;

    for(int i = 1; i <= n; i++) cin >> a[i];
    

    
    bool ans = 0;

    for(int i = 1; i <= n; i++) dp[i][i] = a[i];
    for(int i = n; i >= 1; i--){
        for(int j = i+1; j <= n; j++){
            int opt1 = a[i] + min(dp[i+2][j], dp[i+1][j-1]);
            int opt2 = a[j] + min(dp[i+1][j-1], dp[i][j-2]);

           
            if(opt1 > opt2) ans = 1;
            else ans = 0;
            
            dp[i][j] = max(opt1, opt2);
            
        }
    }

    
    if(ans) cout << dp[1][n] - dp[2][n] << "\n";
    else cout << dp[1][n] - dp[1][n-1] << "\n";


}