#include <bits/stdc++.h>
#include <iostream>

using namespace std;


const int MAXN = 1005;

int n,m,a[MAXN],b[MAXN],dp[MAXN][MAXN];

int main(){
    cin >> n >> m;

    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];

    for(int i = n-1; i >= 0; i--){
        for(int j = m-1; j >= 0; j--){
            if(a[i] == b[j]){
                dp[i][j] = dp[i+1][j+1] + 1;
            }
            else{
                dp[i][j] = max(dp[i+1][j],dp[i][j+1]);
            }
        }
    }

    cout << dp[0][0] << "\n";
}