#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MOD = 1e9+7;

int dp[1<<20][25][2];
int main(){
    int tt; cin >> tt;

    while(tt--){
        int n,m; cin >> n >> m;        

        int k; cin >> k;
        vector<int> good(k);

        for(int i = 0; i < k; i++) cin >> good[i];

        if(m == 1){
            cout << "1\n";
            continue;
        }

        for(int i =0; i < 1<<n; i++) dp[i][1][0] = dp[i][1][1] = i&1;
        
        for(int i = 0; i < 1<<n; i++){
            for(int j = 2; j <= n; j++){
            
                dp[i][j][1] = 1; 
                dp[i][j][0] = 0;
                for(int p : good){
                    if(p > j) break;
                   
                    dp[i][j][0] = max(dp[i][j][0], dp[(((1<<(p-1))-1) & i) + (((((1<<j) - 1) ^ (((1<<p)-1))) & i) >> 1)][j-1][1]);
                    dp[i][j][1] = min(dp[i][j][1], dp[(((1<<(p-1))-1) & i) + (((((1<<j) - 1) ^ (((1<<p)-1))) & i) >> 1)][j-1][0]);
                }
            }
        }

        int ans = 0;
        for(int i = 0; i < 1<<n; i++) ans += dp[i][n][0] + 1;

        cout << ans << "\n";


    }
}