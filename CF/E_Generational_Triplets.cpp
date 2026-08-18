#include <bits/stdc++.h>
#include <iostream>

using namespace std;

typedef long ll;

const int MAXN = 65;
const int MOD = 1e9+7;

ll r;

ll dp[MAXN][2][2][2][2];

//a upper bound, b upper bound, last a & c

int msb(ll x){
    return 63 - __builtin_clzll(x);
}


ll solve(int i, bool au, bool bu,bool lb,  bool nd){
    if(i == -1) return lb;

    if(dp[i][au][bu][lb][nd] != -1) return dp[i][au][bu][lb][nd];

    dp[i][au][bu][lb][nd] = 0;

    for(int a = 0; a <= 1; a++){
        for(int b = 0; b <= 1; b++){
            if((a ^ b) != nd) continue;

            //condition is upper bound lowered or r is 1

            if(!(au || (r & (1LL<<i)) || !a)) continue;
            if(!(bu || (r & (1LL<<i)) || !b)) continue;

            //b has already passed a 
            if(!(lb || (b && !a))) continue;

            dp[i][au][bu][lb][nd] = (dp[i][au][bu][lb][nd] + solve(i-1, au | ((r & (1LL<<i)) && !a),bu | ((r & (1LL<<i)) && !b),lb | (b && !a), a & b)) % MOD;
        }
    }

    return dp[i][au][bu][lb][nd];
}

int main(){
    int tt; cin >> tt;

    while(tt--){
        cin >> r;


        memset(dp, -1, sizeof(dp));

        ll ans = 0;
        for(int a = 0; a <= 1; a++){
            for(int b = 0; b <= 1; b++) ans = (ans + solve(msb(r)-1, ((r & (1LL<<msb(r))) && !a), ((r & (1LL<<msb(r))) && !b), (b && !a), a & b)) % MOD;
        }

        cout << ans << "\n";
    }
}