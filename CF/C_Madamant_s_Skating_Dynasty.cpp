#include <bits/stdc++.h>
#include <iostream>

using namespace std;


#define int long long


const int MOD = 998244353;
const int MAXN = 2e5+5;

int n, a[MAXN], psa[MAXN], fact[MAXN];


int fastpow(int a, int b){
    int res = 1;

    while(b > 0){
        if(b&1) res = (res * a) % MOD;
        b >>= 1;
        a = (a*a) % MOD;
    }

    return res;
}


int minv(int x){
    return fastpow(x, MOD-2) % MOD;
}

int32_t main(){
    int tt; cin >> tt;

    while(tt--){
        cin >> n;

        //psa - i * a[i] all times n! / i


        for(int i= 1; i <= n; i++) cin >> a[i];
        fact[0] = 1;
        for(int i = 1; i <= n; i++) fact[i] = (fact[i-1] * i) % MOD;

        sort(a+1, a+n+1);
        reverse(a+1,a+n+1);

        for(int i = 1; i <= n; i++) psa[i] = a[i] + psa[i-1];


        long long ans = 0;
        for(int i = 2; i <= n; i++) ans = (ans + ((((psa[i-1] - a[i] * (i-1)) % MOD) * fact[n-1]) % MOD * minv((i-1))) % MOD) % MOD;
            
        

        cout << ans << "\n";

       









    }
}