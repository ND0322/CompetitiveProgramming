#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define int long long 

const int MOD = 1e9;

bool flag = 0;

int fastpow(int a, int b){
    int res = 1;

    while(b > 0){
        if(b & 1){
            if(res * a > MOD) flag = 1;
            res = (res * a) % MOD;
        }
        b >>= 1;
        if(a * a > MOD) flag = 1;
        a = (a * a) % MOD;
    }

    return res;
}

int32_t main(){
    int n; cin >> n;

    map<int,int> freq;

    for(int i = 1; i <= n; i++){
        int x; cin >> x;

        for(int j = 2; j * j <= x; j++){
            while(!(x % j)){
                freq[j]++;
                x /= j;
            }
        }

        if(x > 1) freq[x]++;
    }

    map<int,int> freq2;

    int m; cin >> m;
    for(int i = 1; i <= m; i++){
        int x; cin >> x;

        for(int j = 2; j * j <= x; j++){
            while(!(x % j)){
                freq2[j]++;
                x /= j;
            }
        }

        if(x > 1) freq2[x]++;
    }

    long long ans = 1;

    for(auto [x,y] : freq){
        if(ans *fastpow(x, min(y, freq2[x])) > MOD) flag = 1;
        ans = (ans * fastpow(x, min(y, freq2[x]))) % MOD;
    }

    if(flag) cout << setw(9) << setfill('0') << ans << "\n";
    else cout << ans << "\n";
 

}