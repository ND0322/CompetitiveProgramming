#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1e5+5;

int n;

long long dp[MAXN], a[MAXN];

int main(){
    int tt; cin >> tt;

    while(tt--){
        cin >> n;

        for(int i = 0; i < n; i++) cin >> a[i];

        long long suf = 0;
        long long big = 0;

        for(int i = n-1; i >= 0; i--){
            suf += a[i];
            dp[i] = suf + big;
            big = max(big, dp[i]);
        }

        cout << dp[0] << "\n";


    }
}