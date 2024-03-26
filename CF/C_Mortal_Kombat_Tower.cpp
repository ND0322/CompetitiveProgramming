#include <bits/stdc++.h>
#include <iostream>


using namespace std;

const int MAXN = 2e5+5;

int n,dp[MAXN][2];

bool a[MAXN];



int main(){
    int tt; cin >> tt;

    while(tt--){
        cin >> n;

        for(int i = 0; i < n ; i++){
            cin >> a[i];
        }

        dp[n][0] = dp[n][1] = 0;
        

        for(int i = n-1; i >= 0; i--){
            //0 for me
            dp[i][0] = min(dp[i+1][1],dp[min(i+2,n)][1]);
            //1 for friend
            dp[i][1] = dp[i+1][0] + a[i];

            if(i <= n-2){
                dp[i][1] = min(dp[i][1],dp[i+2][0] + a[i] + a[i+1]);
            }
        }

        cout << dp[0][1] << "\n";
    }

}