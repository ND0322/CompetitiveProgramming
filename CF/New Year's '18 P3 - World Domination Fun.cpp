#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1e5+5;

int n,m,k;

long long a[MAXN],st[MAXN<<1]; //gonna use a segtree cause too lazy for diff arr

void update(int l, int r, long long val){
    for(l+=n, r+=n; l < r; l>>=1, r>>=1){
        if(l&1) st[l++] += val;
        if(r&1) st[--r] += val;
    }
}

long long query(int i){
    int res = 0;

    for(i += n; i > 0; i>>=1) res += st[i];
    return res;
}

bool can(int x){
    for(int i = 0; i < n; i++) update(i,i+1,a[i]-query(i));

    /*
    if(x == 3){
        for(int i = 0; i < n; i++) cout << query(i) << " ";
        cout << "\n";
    }
    */

    

    int cnt = k;

    for(int i = 0; i < n; i++){
        long long val = query(i);

        //if(x == 3) cout << i << " " << val << "\n";
        
        if(x-val <= 0) continue;
        if(x-val > cnt) return false;
       

        cnt -= x-val;
        update(i,min(n,i+m+1),x-val);
    }

    return true;


}

int main(){
    cin >> n >> m >> k;

    for(int i = 0; i < n; i++) cin >> a[i];

    

    long long lo = 1;
    long long hi = 2e9;
    long long ans = -1;

    while(lo <= hi){
        long long mid = (lo+hi)>>1;

        if(can(mid)){
            ans = mid;
            lo = mid+1;
        }
        else{
            hi = mid-1;
        }
    }

    cout << ans << "\n";
}