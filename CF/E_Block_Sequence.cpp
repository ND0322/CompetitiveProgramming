#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2e5+5;

int n,a[MAXN],dp[MAXN];

int main(){
    int tt; cin >> tt;

    while(tt--){
        cin >> n;

        for(int i = 0; i < n; i++) cin >> a[i];
        
        dp[n] = 0;

        for(int i = n-1; i >= 0; i--){
            dp[i] = min((i+a[i]+1 > n ? (int)1e9 : dp[i+a[i]+1]),dp[i+1] + 1);
        }

        cout << dp[0] << "\n";
    }
}