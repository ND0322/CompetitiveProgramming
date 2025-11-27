#include <bits/stdc++.h>
#include <iostream>

using namespace std;


/*
any i,j,k

such that a[i] > a[j] > a[k]

dp[i][j][2]

j is max so far

we transition to dp1 if i is less than j and the next is less than i
*/

const int MAXN = 305;

int n, dp[MAXN][MAXN][2], a[MAXN];

int main(){
    int tt; cin >> tt;

    while(tt--){
        cin >> n;

        for(int i = 1; i <= n; i++) cin >> a[i];

        for(int i = n; i >= 0; i--){
            for(int j = 0; j <= n; j++){
                dp[i][j][0] = dp[i+1][j][0];
                dp[i][j][0] += dp[i+1][max(j, a[i+1])][1];

                dp[i][j][1] = dp[i+1][j][0];
                dp[i][j][1] += dp[i+1][max(j, a[i+1])][1];


                if(i == 4 && j == 6) cout << dp[i+1][j][0] << " " << dp[i+1][max(j, a[i+1])][1] << "\n";
                for(int k = i+1; k <= n; k++){
                    if(j > a[i] && a[i] > a[k]) dp[i][j][1] += 1<<(n-k);
                }
            }
        }

        cout << dp[4][3][1] << "\n";
        cout << dp[]

        cout << pow(2,n) - dp[0][0][0] << "\n";
    }
}