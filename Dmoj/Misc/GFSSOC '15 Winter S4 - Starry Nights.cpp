#include <bits/stdc++.h>
#include <iostream>

using namespace std;

//precomp the good crap


#define int long long
const int MOD = 1e9+7;

int r,c, dp[105][3005], cnt, good[3005];

void build(int i, int mask){
    if(i >= c-1) return void(good[cnt++] = mask);
    build(i+1,mask);
    if(i < c-1) build(i+3, mask | (1<<i));
}

int32_t main(){
    cin >> r >> c;

    build(1,0);

    for(int i = 0; i < cnt; i++) dp[0][i] = 1;

    for(int i = 1; i < r-1; i++){
        for(int j = 0; j < cnt; j++){
            for(int k = 0; k < cnt; k++){
                //they have to be disjoint

                if(good[j] & good[k]) continue;
                if((good[j]<<1)&good[k])continue;
                if((good[j]>>1)&good[k]) continue;

                dp[i][j] = (dp[i][j] + dp[i-1][k]) % MOD;
            }
        }
    }

    long long ans = 0;

    for(int i = 0; i < r-1; i++){
        for(int j = 0; j < cnt; j++){
            if(good[j]) ans = (ans+dp[i][j]) % MOD;
        }
    }

    cout << ans << "\n";
}
