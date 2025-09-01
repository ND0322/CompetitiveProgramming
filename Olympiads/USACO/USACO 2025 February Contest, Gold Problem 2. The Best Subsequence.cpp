#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MOD = 1e9+7;
const int MAXQ = 2e5+5;

#define int long long



int fastpow(int a, int b){
    long long ans = 1;
    while(b){
        if(b&1) ans = (ans*a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }

    return ans;
}




int32_t main(){
    cin >> n >> m >> q;

    vector<int> runs;
    map<int,int> events;

    while(m--){
        int l,r; cin >> l >> r;

        events[l]++;
        events[r+1]++;
    }

    int cur = 1;

    

    sort(events.begin(), events.end());



    while(q--){
        int l,r,k; cin >> l >> r >> k;

        if(qcnt(rt,1,n,l,r) >= k){
            cout << (fastpow(2,k) - 1 + MOD) % MOD << "\n";
            continue;
        }

        int lo = l-1;
        int hi = r;

        int i = -1;

        while(lo <= hi){
            int mid = (lo+hi)>>1;

            if(qcnt(rt,1,n, l, mid) + r - mid >= k){
                lo = mid+1;
                i = mid;
            }
            else hi = mid-1;
        }

        int rs = qsm(rt,1,n,i+1, r) * fastpow(fastpow(2, n-r), MOD-2) % MOD;

        
        cout << ((((fastpow(2, qcnt(rt,1,n,l,i)) - 1 + MOD) % MOD) * fastpow(2, r-i)) % MOD + rs) % MOD<< "\n";
    }
    
}


