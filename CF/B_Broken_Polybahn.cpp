#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define int long long 

const int MAXN = 2e5+5;
const int MOD = 1e9+7;



int n, deg[MAXN];

int pow(int a, int b){
    int ans = 1;
    while(b){ 
        if (b&1) ans = (ans*a) % MOD;
        b /= 2;
        a = (a*a) % MOD;
    }
    return ans;
}
int32_t main(){
    cin >> n;

    for(int i = 0; i < n-1; i++){
        int x,y; cin >> x >> y;

        deg[x]++;
        deg[y]++;
    }

    long long ans = 0;

    for(int i = 1; i <= n; i++) ans = (ans + pow(2LL,deg[i]))%MOD;
    ans -= 2*n;
    ans += 1;

    ans = (ans + MOD) % MOD;

    cout << ans << "\n";
}