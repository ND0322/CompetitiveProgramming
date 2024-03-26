#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 505;

int n, can[MAXN][MAXN],dp[MAXN][MAXN],a[MAXN],mx[MAXN][MAXN],mn[MAXN][MAXN];

int main(){
    int tt; cin >> tt;

    while(tt--){
        cin >> n;

        for(int i = 0; i < n; i++){
            cin >> a[i];

            can[i][i] = 1;
            mx[i][i] = a[i];
            mn[i][i] = a[i];

        }

        for(int i = n-1; i >= 0; i--){
            for(int j = i+1; j < n; j++){
                if(can[i][j-1] && a[j] > a[j-1]){
                    can[i][j] = 1;
                }
                else{
                    can[i][j] = 0;
                }

                mx[i][j] = max(a[j], mx[i][j-1]);
                mn[i][j] = min(a[j],mn[i][j-1]);


            }
        }

        for(int i = n-1; i >= 0; i--){
            for(int j = i+1; j < n; j++){
                if(can[i][j]){
                    dp[i][j] = 0;
                    continue;
                } 


                if(j == i+1){
                    dp[i][j] = 1;

                    continue;
                }

                dp[i][j] = j-i;

                for(int k = i; k <= j; k++){

                    

                    if(mn[k+1][j] > mx[i][k]){
                        dp[i][j] = min(dp[i][j],dp[i][k] + dp[k+1][j]);
                        
                        
                        }
                   
                }
            }
        }

        int ans = 0;

        for(int i = n-1; i >= 0; i--){
            for(int j = i+1; j < n; j++){
                ans += dp[i][j];

                //cout << i << " " << j << " " << dp[i][j] << "\n";
            }
        }

        cout << ans << "\n";

        
    }
}