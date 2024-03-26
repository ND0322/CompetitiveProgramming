#include <bits/stdc++.h>
#include <iostream>

using namespace std;

//dp state is i, last placed



const int MAXN = 2505;
const int MOD = 998244353;

int n,k;

int main(){
    cin.tie(NULL) -> ios_base::sync_with_stdio(0);
    int tt; cin >> tt;

    while(tt--){
        cin >> n >> k;


        vector<vector<int>> dp(n+1, vector<int>(k+1,0));
        for(int i = 1; i <= k; i++) dp[0][i] = 1;
        

        long long ans = 0;

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= k; j++){
                for(int nxt = 1; nxt * j <= i && j+nxt-1 <= k; nxt++) dp[i][j] = (dp[i][j] + dp[i-nxt*j][nxt]) % MOD;
            }
        }

        

        for(int i = 1; i <= k; i++) ans = (ans+dp[n][i])%MOD;
        cout << ans << "\n";

        
    }
}