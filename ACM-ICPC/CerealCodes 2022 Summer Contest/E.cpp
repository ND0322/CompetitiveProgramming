#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1e5+5;
const int MOD = 1e9+7;

long long pw[MAXN], psa[MAXN];

int main(){
    pw[0] = 1;
    for(int i = 1; i < MAXN; i++) pw[i] = (pw[i-1]<<1) % MOD;

    for(int i = 1; i < MAXN; i++) psa[i] = (psa[i-1] + (pw[i-1] - pw[i/2] + MOD) % MOD)%MOD;

    int q; cin >> q;

    while(q--){
        int l,r; cin >> l >> r;

        cout << (psa[r] - psa[l-1] + MOD)%MOD << "\n";
    }
}