#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 3e5+5;
const int MOD = 998244353;

int n;

pair<int,int> st[MAXN<<1];

void update(int i, pair<int,int> x){
    for(st[i+=n] = x; i > 1; i>>=1) st[i>>1] = min(st[i], st[i^1]);
}
pair<int,int> query(int l, int r){
    pair<int,int> ans = {1e9+1,-1};
    for(l += n, r+=n; l < r; l>>=1, r>>=1){
        if(l&1) ans = min(ans, st[l++]);
        if(r&1) ans = min(ans, st[--r]);
    }
    return ans;
}

long long dac(int l, int r){

    if(l > r) return 1LL;

    int split = query(l,r+1).second;

    long long f = dac(l, split-1);
    long long s = dac(split+1,r);

    long long ans = (f*s)%MOD;

    if(r != n-1) ans = (ans+f)%MOD;
    if(l) ans = (ans+s)%MOD;
    //PIE
    if(l && r != n-1) ans = (ans + (-1) % MOD)%MOD;
    return ans;
}

int main(){
    int tt; cin >> tt;

    while(tt--){
        cin >> n;

        for(int i = 0; i < n; i++){
            int x; cin >> x;

            update(i, {x,i});
        }

        cout << dac(0,n-1) << "\n";


    }
}