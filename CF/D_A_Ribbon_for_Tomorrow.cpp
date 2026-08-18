#include <bits/stdc++.h>
#include <iostream>


using namespace std;

#define int long long

const int MOD = 998244353;
const int MAXN = 1e6+5;


int fact[MAXN], ifact[MAXN];

int fastpow(int a, int b){
    int res = 1;

    while(b > 0){
        if(b&1) res = (res * a) % MOD;
        b >>= 1;
        a = (a*a) % MOD;
    }
    return res;
}


int choose(int a, int b){
    if(!b) return 1;
    return ((fact[a] * ifact[b]) % MOD * ifact[a-b]) % MOD;
}

int32_t main(){
    int tt; cin >> tt;

    fact[0] = 1;
    for(int i = 1; i <= 1e6; i++) fact[i] = (fact[i-1] * i) % MOD;
    ifact[0] = 1;
    for(int i = 1; i <= 1e6; i++) ifact[i] = (ifact[i-1] * fastpow(i, MOD-2)) % MOD;

    while(tt--){
        int n; cin >> n;

        vector<int> a(n+1);

        /*
        number of strings with same amount of runs
        */

        int minv = fastpow(2, MOD-2);
    

        int cnt[2] = {0,0};
        for(int i = 1; i <= n; i++){
            char c; cin >> c;

            a[i] = c - '0';

            cnt[a[i]]++;
        }  

        int c[2] = {0,0};

        for(int i = 1; i <= n; i++){
            if(i == n || a[i+1] != a[i]) c[a[i]]++;
        }

        int ans = 1;
        if(c[1]) ans = (ans * choose(cnt[1]-1, c[1]-1)) % MOD;
        if(c[0]) ans = (ans * choose(cnt[0]-1, c[0]-1)) % MOD;
        cout << ans << "\n";




       
    }
}