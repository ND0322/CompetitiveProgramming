#include <bits/stdc++.h>
#include <iostream>

using namespace std;
#define int long long

const int MAXN = 20;

long long l, r,n, dp[MAXN][2][2];

long long solve(int i, bool lo, bool hi){
    if(i == -1) return 0;

    if(dp[i][lo][hi] != -1) return dp[i][lo][hi];

    for(int j =0; j < 10; j++){
        if(!lo && j > (r / (int)pow(10, i)) % 10) continue;
        if(!hi && j < (l / (int)pow(10, i)) % 10) continue;

       

        dp[i][lo][hi] = max(dp[i][lo][hi], solve(i-1, lo || j < ((r / (int)pow(10, i)) % 10), hi || j > ((l / (int)pow(10, i)) % 10)) + j);
    }
    return dp[i][lo][hi];
}

int32_t main(){
    int tt; cin >> tt;

    while(tt--){
        cin >> l >> r;

        memset(dp, -1, sizeof(dp));

        cout << solve(log10(r), 0, 0) << "\n";
    }
}  