#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MOD = 998244353;
const int MAXN = 2e5+5;

int n, x, dp[MAXN], a[MAXN];

long long fast_power(long long base, long long power) {
    long long result = 1;
    while(power > 0) {

        if(power & 1) {
            result = (result*base) % MOD;
        }
        base = (base * base) % MOD;
        power >>= 1; 
    }
    return result;
}

long long minv(long long x){
    return (x * fast_power(n, MOD - 2));
}


int solve(int val){
    if(dp[val] == -1){

        int ans = 0;
        for(int i = 1; i <= n; i++){
            if(val + a[i] <= x) ans = (ans + minv(solve(val + a[i]))) % MOD;
            else if(i == 1) ans = (ans + minv(1)) % MOD;
            
        }

        dp[val] = ans;
    }
    return dp[val];
}  



int main(){
    cin >> n >> x;


    memset(dp,-1,sizeof(dp));


    for(int i = 1; i <= n; i++) cin >> a[i];

    cout << solve(0) << "\n";

    


    

    
}
