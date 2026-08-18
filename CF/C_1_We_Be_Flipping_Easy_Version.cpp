#include <bits/stdc++.h>
#include <iostream>

using namespace std; 

#define int long long

const int MAXN = 2e5+5;

int n, dp[MAXN][2], a[MAXN], nxt[MAXN][2];

int32_t main(){
    int tt; cin >> tt;

    while(tt--){
        cin >> n;
        for(int i = 1; i <= n; i++) cin >> a[i];


        for(int i = 1; i <= n; i++){


            for(int j = 0; j < 2; j++){
                //not flip

                dp[i][j] = dp[i-1][j] + (int)pow(-1, j) * a[i];
                nxt[i][j] = 0;

                if(pow(-1, j) * a[i] > 0 && dp[i-1][!j] + (int)pow(-1, !j) * a[i] < dp[i][j]){
                    dp[i][j] = dp[i-1][!j] + (int)pow(-1, !j) * a[i];
                    nxt[i][j] = 1;
                }
    
                
            }
        }


        bool cur = 0;

        vector<int> ans;

        for(int i = n; i >= 1; i--){
            if(nxt[i][cur]){
                cur = !cur;
                ans.push_back(i);
            }
        }

        cout << ans.size() << "\n";

        for(int i : ans) cout << i << " ";
        cout << "\n";


        
        
    }
}