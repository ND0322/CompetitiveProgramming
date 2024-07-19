#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define int long long

const int MOD = 1e9+7;



int qpow(int a, int b){
    int ans = 1;
    while(b){
        if (b&1) ans = (ans*a) % MOD;
        b >>=1;
        a = (a*a) % MOD;
    }
    return ans;
}

int32_t main(){
    int n; cin >> n;

    cout << (qpow(3,3*n) - qpow(7, n) + MOD) % MOD << "\n";

    


}