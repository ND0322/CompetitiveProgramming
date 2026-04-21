#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 5005;

int n, a[MAXN], b[MAXN], c[MAXN], dp[MAXN][MAXN];

int main(){
    cin >> n;

    int m = 0;

    for(int i = 1; i <= n; i++){
        cin >> c[i];
        m = max(m, c[i]);
    }
    
    for(int i = 1; i <= n; i++) cin >> a[i] >> b[i];
    

    for(int i = n; i >= 1; i--){
        for(int j = 0; j <= m; j++){
            //cur value is j

            //we can keep pouring from last even after this is full

            dp[i][j] = 1e9;
            if(j * b[i-1] > c[i]) continue;
            int cnt = ceil((c[i] - j * b[i-1]) / (double)a[i]);

            
            
            
            for(int k = 0; cnt + k <= m; k++) dp[i][j] = min(dp[i][j], dp[i+1][cnt+k] + cnt + k);

        }
    }

    cout << dp[1][0] << "\n";
    
}