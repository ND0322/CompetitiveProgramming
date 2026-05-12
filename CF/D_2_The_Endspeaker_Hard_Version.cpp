#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MOD = 1e9+7;


int main(){
    int tt; cin >> tt;

    while(tt--){
        int n, m; cin >> n >> m;

        vector<long long> psa(n+1);
        
        vector<int> b(m+1);

        for(int i = 1; i <= n; i++){
            cin >> psa[i];
            psa[i] += psa[i-1];
        }
        for(int i = 1; i <= m; i++) cin >> b[i];

        vector<vector<long long>> dp(n+5, vector<long long> (m+5, 1e9));
        vector<vector<long long>> dp2(n+5, vector<long long> (m+5, 0));
        vector<vector<long long>> dps(n+5, vector<long long> (m+5, 0));

        for(int i = 1; i<= m; i++){
            dp[n+1][i] = 0;
            dp2[n+1][i] = 1;
            dps[n+1][i] = 1;
        }
        for(int i = n; i >= 1; i--){
            for(int j = m; j >= 1; j--){
                if(j != m){
                    dp[i][j] = dp[i][j+1];
                    dp2[i][j] = dp2[i][j+1];
                }

                int lo = i;
                int hi = n;

                int nxt = -1;

                while(lo <= hi){
                    int mid = (lo+hi)>>1;

                    if(psa[mid] - psa[i-1] <= b[j]){
                        nxt = mid;
                        lo = mid+1;
                    }
                    else hi = mid-1;
                }

                if(nxt == -1) continue;

                if(dp[i][j] < dp[nxt+1][j] + m- j) continue;
                bool add = 0;
                if(dp[i][j] == dp[nxt+1][j] + m - j) add = 1;
                dp[i][j] = dp[nxt+1][j] + m - j;

                

                int sm = 0;

                lo = i;
                hi = nxt;

                int l = nxt;

                while(lo <= hi){
                    int mid = (lo+hi)>>1;


                    
                    if(dp[mid+1][j] == dp[nxt+1][j]){
                        l = mid;
                        hi = mid-1;
                    }
                    else lo = mid+1;
                }
            
                

                if(add) dp2[i][j] = (dp2[i][j] + (dps[l+1][j] - dps[nxt+2][j] + MOD) % MOD) % MOD;
                else dp2[i][j] = (dps[l+1][j] - dps[nxt+2][j] + MOD) % MOD;

            }

            for(int j = 1; j <= m; j++) dps[i][j] = (dp2[i][j] + dps[i+1][j]) % MOD;
        }


        if(dp[1][1] == 1e9){
            cout << "-1\n";
            continue;
        }

        cout << dp[1][1] << " " << dp2[1][1] << "\n";
        



    }
}