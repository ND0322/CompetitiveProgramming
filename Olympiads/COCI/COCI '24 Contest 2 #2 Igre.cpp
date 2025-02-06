#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 5005;

int n,k, a[MAXN], b[MAXN], c[MAXN], dp[MAXN][MAXN][2];

int main(){
    cin >> n >> k;

    

    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];
    for(int i = 1; i <= n; i++) cin >> c[i];

    for(int i = 1; i <= n; i++) cout << a[i] << " ";
    cout << "\n";

    for(int i = 1; i <= n; i++) cout << b[i] << " ";
    cout << "\n";

    for(int i = 1; i <= n; i++) cout << c[i] << " ";
    cout << "\n";

    for(int i = n; i >= 1; i--){
        for(int j = 0; j <= k; j++){
            dp[i][j][1] = dp[i+1][j][0];

            

            if(j - b[i] >= 0) dp[i][j][1] = max(dp[i][j][1], dp[i][j-b[i]][1] + c[i]);

            dp[i][j][0] = dp[i+1][j][0];

            if(j - a[i] >= 0) dp[i][j][0] = max(dp[i][j][0], dp[i][j-a[i]][1]); 
        }
    }

    cout << dp[1][k][0] << "\n";


}