#include <bits/stdc++.h>
#include <iostream>

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>


using namespace std;
using namespace __gnu_pbds;


#define int long long


typedef tree<
int,
null_type,
less_equal<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ost;



const int MAXN = 3e5+5;

int n, a[MAXN], m, cnt[MAXN];

long long k;
/*
bsearch on answer

minimum number of gems

for each cart we need to guarentee num less in the suffix <= side track

0s will always form an increasing sequence and we keep adding from the back 
*/


struct Node{
    int lz = -1;
    int sm = 0;
    int mn = 0;
    
} st[MAXN<<2];

inline void pushdown(int node, int l, int r, int mid){
    if(st[node].lz == -1) return;
    st[node<<1].lz = st[node].lz;
    st[node<<1|1].lz = st[node].lz;

    st[node<<1].mn = st[node].lz;
    st[node<<1|1].mn = st[node].lz;
    
    st[node<<1].sm = st[node].lz * (mid-l+1);
    st[node<<1|1].sm = st[node].lz * (r-mid);
    

    
    st[node].lz = -1;
}

inline void build(int node, int l, int r){
    st[node].lz = -1;
    st[node].sm = 0;
    st[node].mn = 0;
    if(l == r) return;
    int mid = (l+r)>>1;
    build(node<<1, l, mid);
    build(node<<1|1, mid+1,r);
    st[node].sm = st[node<<1].sm + st[node<<1|1].sm;
}


inline void update(int node, int l, int r, int x, int y, int v){
    if(x > r || y < l) return;
    if(x <= l && y >= r){
        st[node].lz = v;
        st[node].sm = v * (r-l+1);
        st[node].mn = v;
        return;
    }

    int mid = (l+r)>>1;
    pushdown(node, l, r, mid);
    update(node<<1, l, mid, x, y, v);
    update(node<<1|1, mid+1, r, x,y,v);
    st[node].sm = st[node<<1].sm + st[node<<1|1].sm;
    st[node].mn = min(st[node<<1].mn, st[node<<1|1].mn);
}

inline int query(int node, int l, int r, int x, int y){
    if(x > r || y < l) return 0;
    if(x <= l && y >= r) return st[node].sm;
    int mid = (l+r)>>1;
    pushdown(node, l, r, mid);
    return query(node<<1, l, mid, x, y) + query(node<<1|1, mid+1, r, x, y);
}

inline int qr(int node, int l, int r, int x, int y, int v){
    if(x > r || y < l) return -1;
    if(st[node].mn > v) return -1;
    if(l == r) return l;

    int mid = (l+r)>>1;
    pushdown(node, l, r, mid);
    int right = qr(node<<1|1, mid+1,r,x,y,v);
    if(right != -1) return right;
    return qr(node<<1, l, mid, x, y, v);
}



bool can(int x){
    long long tot = 0;
    build(1,1,m+1);
    int l = m+1;
    for(int i = n; i >= 1; i--){

        if(a[i] == 0){
            l--;
            continue;
        }

        if(cnt[i] > x) return 0;
        int r = qr(1,1,m+1, l, m, a[i]);

        if(r == -1) continue;
        
        if(cnt[i] + r - l + 1 <= x) continue;
        tot += (r  - l -x + cnt[i] + 1) * a[i] - query(1,1,m+1, l+x-cnt[i], r);
        update(1,1,m+1, l+x-cnt[i], r, a[i]);
    }
    return tot <= k;
}

int32_t main(){
    cin.tie(NULL) -> ios_base::sync_with_stdio(0);
    cin >> n >> k;

    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(a[i] == 0) m++;
    }


    

    int lo = 0;

    ost s;

    for(int i = n; i >= 1; i--){
        if(!a[i]) continue;
        lo = max(lo,(int)s.order_of_key(a[i]));
        cnt[i] = (int)s.order_of_key(a[i]);
        s.insert(a[i]);
    }
    int hi = n;

    int ans = 0;

    while(lo <= hi){
        int mid = (lo+hi)>>1;

        if(can(mid)){
            hi = mid-1;
            ans = mid;
        }
        else lo = mid+1;
    }

    cout << ans << "\n";

    
}