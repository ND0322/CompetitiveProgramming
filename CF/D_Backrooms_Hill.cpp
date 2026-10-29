#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2e5+5;

int n, a[MAXN];

bool dp[MAXN][2][2];

bool p[MAXN];
int main(){

    int tt; cin >> tt;

    while(tt--){
        cin >> n;

        

        for(int i = 1; i <= n; i++){
            cin >> a[i];
            p[a[i]] =i & 1;
        }


        for(int j = 0; j < 2; j++){
            for(int k = 0; k < 2; k++) dp[n+1][j][k] = 1;
        }
        
        for(int i = n; i >= 1; i--){
            for(int j = 0; j < 2; j++){
                for(int k = 0; k < 2; k++){
                    dp[i][j][k] = 0;
                    if(p[i] == j) dp[i][j][k] |= dp[i+1][!j][k];
                    if(p[i] == k) dp[i][j][k] |= dp[i+1][j][!k];
                }
            }
        }

        cout << (dp[1][1][n&1] ? "YES\n" : "NO\n");

        



    }
}