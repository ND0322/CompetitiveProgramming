#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define int long long

const int MOD = 998244353;

int fastpow(int a, int b){
    int res = 1;
    while(b > 0){
        if(b & 1) res = (res * a) % MOD;
        b >>= 1;
        a = (a*a) % MOD;
    }
    return res;
}

int32_t main(){
    int tt; cin >> tt;

    while(tt--){
        int n,m,r,c; cin >> n >> m >> r >> c;


        int tmp = (r-1) * m + (c-1) * n - (r-1) * (c-1);

        cout << fastpow(2,tmp) << "\n";
    }
}