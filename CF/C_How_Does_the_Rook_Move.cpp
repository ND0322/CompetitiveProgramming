#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 3e5+5;
const int MOD = 1e9+7;

int n, k;

long long dp[MAXN];

//dp => number of ways to place i rooks
//always can place an (x,x)

int main(){
    dp[0] = 1;
    dp[1] = 1;

    for(int i = 2; i < MAXN; i++) dp[i] = (dp[i-1] + dp[i-2] * (i-1) * 2) % MOD;

    int tt; cin >> tt;

    while(tt--){
        cin >> n >> k;

        while(k--){
            int x,y; cin >> x >> y;

            if(x == y) n--;
            else n-=2;
        }

        cout << dp[n] << "\n";


    }
}