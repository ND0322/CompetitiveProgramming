#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 755;

int n, has[MAXN][MAXN], req[MAXN][MAXN];

long long dp[MAXN][MAXN];

int main(){
    cin >> n;

    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            char c; cin >> c;

            req[i][j] = (c=='1');
        }
    }

    for(int i = n-1; i >= 0; i--){
        for(int j = i+1; j < n; j++){
            for(int k = i; k < j; k++){
                dp[i][j] += dp[i][k] * has[k][j];
            }
            
            has[i][j] = (dp[i][j] & 1) != req[i][j];
            dp[i][j] += has[i][j];
        }
    }
   
    int ans = 0;


    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) ans += has[i][j];
    }

    cout << ans << "\n";
}