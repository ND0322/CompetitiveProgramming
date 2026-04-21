#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 4e5+5;
const int MOD = 1e9+7;

#define int long long

int n, m, q, cnt[MAXN], val[MAXN], psa[MAXN];

pair<pair<int,int>, int> ranges[MAXN];


/*
get intervals with line sweep

binary search for first mid such that cnt(l, mid) + r - mid == k

cnt is number of 1s on interval 

on intervals disjoint
find position in sorted array of intervals by l and do psa for middle and some logic for ends to find number of 1s
Assume we have k blocks, with size a1, a2, a3 ... ak respectively
*/

int fastpow(int a, int b){

    int res = 1;
    while(b > 0){
        if(b&1) res = (res * a) % MOD;
        a = (a*a) % MOD;
        b >>= 1;
    }
    return res;
}

int ones(int l, int r){
    int lo = 1;
    int hi = m;
    int ll = -1;

    while(lo <= hi){
        int mid = (lo+hi)>>1;

        if(ranges[mid].first.first >= l){
            hi = mid-1;
            ll = mid;
        }
        else lo = mid+1;
    }

    if(r < ranges[ll].first.second){
        if(ll == 1) return 0;
        return ranges[ll-1].second * (ranges[ll-1].first.second - ranges[ll-1].first.first+1);
    }

    lo = ll;
    hi = m;
    int rr = -1;

    while(lo <= hi){
        int mid = (lo+hi)>>1;

        if(ranges[mid].first.second <= r){
            lo = mid+1;
            rr = mid;
        }
        else hi = mid-1;
    }


    int res = cnt[rr] - cnt[ll-1];


    if(ll != 1 && ranges[ll-1].second) res += max(ranges[ll].first.first - l, 0LL);
    if(rr != m && ranges[rr+1].second) res += max(r - ranges[rr].first.second, 0LL);


    return res;
}

int getsm(int l, int r){
    int lo = 1;
    int hi = m;
    int ll = 1;

    while(lo <= hi){
        int mid = (lo+hi)>>1;

        if(ranges[mid].first.first >= l){
            hi = mid-1;
            ll = mid;
        }
        else lo = mid+1;
    }

    

    lo = ll;
    hi = m;
    int rr = 1;

    while(lo <= hi){
        int mid = (lo+hi)>>1;

        if(ranges[mid].first.second <= r){
            lo = mid+1;
            rr = mid;
        }
        else hi = mid-1;
    }
    
    cout << l << " " << r << " " << ll << " " << rr << "\n";
    int res = (psa[rr] - psa[ll-1] + MOD) % MOD;

    if(ll != 1 && ranges[ll-1].second) res = (res + max(((fastpow(2, ranges[ll].first.first - l)-1+MOD)%MOD * (fastpow(2, n - ranges[ll].first.first)) % MOD) % MOD, 0LL)) % MOD;
    if(rr != m && ranges[rr+1].second) res = (res + max(((fastpow(2, r - ranges[rr].first.second)-1+MOD)%MOD * (fastpow(2, n - r)) % MOD) % MOD, 0LL)) % MOD;

    return res;
}



int32_t main(){
    cin >> n >> m >> q;

    map<int,int> events;

    for(int i = 1; i <= m; i++){
        int l,r; cin >> l >> r;

        events[l] ^= 1;
        events[r+1] ^= 1;
    }

   
    int ind = 0;
    int lastI = 1;
    int cur = events[1];
    int last = events[1];

    for(auto [pos, x] : events){
        if(pos == 1) continue;

        cur ^= x;

        if(cur != last){
            ranges[++ind] = {{lastI, pos-1}, last};
            lastI = pos;
            last = cur;
        }
    }

    

    m = ind;

    for(int i = 1; i <= m; i++) cout << ranges[i].second << " ";
    cout << "\n";
    for(int i = 1; i <= m; i++) cout << ranges[i].first.second - ranges[i].first.first + 1 << " ";
    cout << "\n";
    for(int i = 1; i <= m; i++) cout << ranges[i].first.first << " " << ranges[i].first.second << "\n";

    

    for(int i = 1; i <= m; i++) cnt[i] = cnt[i-1] + ranges[i].second * (ranges[i].first.second - ranges[i].first.first+1);
    
    int pw = 0;
    for(int i = m; i >= 1; i--){
        int length = ranges[i].first.second - ranges[i].first.first+1;

        if(ranges[i].second)
            val[i] = ((fastpow(2, length) - 1 + MOD) % MOD * fastpow(2, pw)) % MOD;

        pw = (pw + length) % (MOD-1);
    }  
    for(int i = 1; i <= m; i++) psa[i] = (psa[i-1] + val[i]) % MOD;
        

    while(q--){
        int l,r, k; cin >> l >> r >> k;

        if(ones(l,r) >= k){
            cout << (fastpow(2, k)-1+MOD) % MOD << "\n";
            continue;
        }

        int lo = l;
        int hi = r;

        int pos = l;

        while(lo <= hi){
            int mid = (lo+hi)>>1;

            if(ones(l, mid) + r-mid >= k){
                lo = mid+1;
                pos = mid;
            }
            else hi = mid-1;
        }

        cout << "E " << l << " " << pos << " " << ones(l,pos) << "\n";

        int p1 = ((fastpow(2, ones(l,pos)) - 1) * fastpow(2, k-ones(l,pos))) % MOD;

        

        int p2 = (getsm(pos+1, r) * fastpow(fastpow(2, n-r), MOD-2)) % MOD;

        cout << (p1 + p2) % MOD << "\n";
    }

    
}