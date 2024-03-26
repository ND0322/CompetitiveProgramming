#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1e6+5;

int n, q, k;

struct Node{
    int sum;

    bool lz;
} st[MAXN<<2];

void pushdown(int node, int l, int r){

    if(!st[node].lz) return;
    int mid = (l+r)>>1;

    st[node<<1].sum = (mid-l+1) - st[node<<1].sum;
    st[node<<1|1].sum = (r-mid) - st[node<<1|1].sum;

    st[node<<1].lz ^= st[node].lz;
    st[node<<1|1].lz ^= st[node].lz;

    st[node].lz = 0;
}

void build(int node, int l, int r){
    st[node].lz = 0;
    if(l == r){
        st[node].sum = 1;
        return;
    }

    int mid = (l+r)>>1;

    build(node<<1,l,mid);
    build(node<<1|1,mid+1,r);   
    st[node].sum = st[node<<1].sum + st[node<<1|1].sum;
}

void update(int node, int l, int r, int x, int y){
    if(x > r || y < l) return;
    if(x <= l && y >= r){
        st[node].sum = (r-l+1) - st[node].sum;
        st[node].lz ^= 1;
        return;
    }

    int mid = (l+r)>>1;
    pushdown(node,l,r);
    update(node<<1,l,mid,x,y);
    update(node<<1|1,mid+1, r, x,y);
    st[node].sum = st[node<<1].sum + st[node<<1|1].sum;
}

//could add fractional cascading to optimize

int query(int node, int l, int r, int x, int y){
    if(x > r || y < l) return 0;
    if(x <= l && y >= r) return st[node].sum;

    int mid = (l+r)>>1;
    pushdown(node,l,r);
    return query(node<<1,l,mid, x, y) + query(node<<1|1,mid+1,r,x,y);
}

int main(){
    cin.tie(NULL) -> ios_base::sync_with_stdio(0);
    cin >> n >> q >> k;

    build(1,1,n);

    while(q--){
        int l,r; cin >> l >> r;

        update(1,1,n,l,r);

        int lo = 1;
        int hi = n;

        int ans = -1;

        while(lo <= hi){
            int mid = (lo+hi)>>1;

            if(query(1,1,n,1,mid) >= k){
                ans = mid;
                hi = mid-1;
            }
            else lo = mid+1;
        }

        if(ans == -1) cout << "AC?\n";
        else cout << ans << "\n";
    }
}