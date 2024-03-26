#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

const int MAXN = 105;
const int INF = 1e9;

int n,a[MAXN],dp[MAXN][MAXN];

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);    
}

int wrap(int x){
    return (x+n)%n;
}


void solve(){

    for(int i = 0; i < n; i++) cin >> a[i];

    for(int i = 0; i < n; i++){
        dp[i][i] = gcd(a[(i+n-1) % n],a[(i+n+1) % n]);
    }

    for(int l = 1; l < n-2; l++){

        for(int i = n-1; i >= 0; i--){
            
            int j = (i+l)%n;

            dp[i][j] = min(dp[(i+n+1)%n][j],dp[i][(j+n-1)%n]);

            //split the range

            for(int k = (i+n+1)%n; k != j; k = (k+n+1)%n) dp[i][j] = min(dp[i][j],dp[i][(k+n-1)%n] + dp[(k+n+1)%n][j]);
            dp[i][j] += gcd(a[(i+n-1) % n],a[(j+n+1) % n]);

        }
    }

    int ans = INF;

    //all last 2 pairs

    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            ans =min(ans,gcd(a[i],a[j]) + dp[(i+n+1)%n][(j+n-1)%n] + dp[(j+n+1)%n][(i+n-1)%n]);
        }
    }

    cout << ans << "\n";

}

int main(){
    while(1){
        cin >> n;

        if(!n) break;
        solve();
    }
}