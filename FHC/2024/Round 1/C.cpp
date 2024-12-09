#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MOD = 998244353;

//use ulimit -s unlimited

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int tt; cin >> tt;

    for(int _ = 1; _ <= tt; _++){

        long long w,g,l; cin >> w >> g >> l;

        l %= MOD;

        cout << "Case #" << _ << ": " << (((2*l+1) % MOD) * ((w-g) % MOD)) % MOD << "\n";
    }
}