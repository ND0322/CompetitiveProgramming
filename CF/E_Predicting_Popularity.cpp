#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2e6+5;
const int MAXM = 5e5+5;

struct Node{
    int lz =0, mn =0;
} st[MAXN<<2];

int n, A, B, a[MAXM], b[MAXM]; 


void pushdown(int node, int l, int r, int mid){
    if(!st[node].lz) return;


    st[node<<1].lz += st[node].lz;
    st[node<<1|1].lz += st[node].lz;
    st[node<<1].mn += st[node].lz;
    st[node<<1|1].mn += st[node].lz;

    st[node].lz = 0;
}

void update(int node, int l, int r, int x, int y,int v){
    if(x > r || y < l) return;
    if(x <= l && y >= r){
        st[node].lz += v;
        st[node].mn += v;
        return;
    }

    int mid = (l+r)>>1;
    pushdown(node, l, r, mid);
    update(node<<1, l, mid, x, y, v);
    update(node<<1|1, mid+1,r,x,y,v);
    st[node].mn = min(st[node<<1].mn, st[node<<1|1].mn);
}

int query(int node, int l, int r, int x, int y){
    if(l == x && r == y && st[node].mn >= 0) return -1;
    if(l == r) return l;

    int mid = (l+r)>>1;
    pushdown(node, l, r, mid);
    if(y <= mid) return query(node<<1, l, mid, x, y);
    else if(x > mid) return query(node<<1|1, mid+1, r, x, y);
    else{
        int res = query(node<<1, l , mid,x, mid);
        return (res != -1 ? res :  query(node<<1|1, mid+1 , r,mid+1, y));
    } 
}

int qsm(int node, int l, int r, int x, int y){
    if(x > r || y < l) return 1e9;
    if(x <= l && y >= r) return st[node].mn;

    int mid = (l+r)>>1;
    pushdown(node, l, r, mid);
    return min(qsm(node<<1,l, mid, x,y), qsm(node<<1|1, mid+1,r,x,y));
}

/*
each point has a fixed threshold value call this k
sort by this
bsearch on a prefix
build segtree on k

psum >= i for each i 
*/
int main(){
    cin.tie(NULL) -> ios_base::sync_with_stdio(0);
    cin >> A >> B;

    cin >> n;


    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];

    for(int i = 0; i <= 2e6; i++) update(1,0,2e6, i,i, -i);
    for(int i = 1; i <= n; i++){
        int p = max(a[i] - A, 0) + max(b[i] - B, 0);
        update(1,0,2e6, p+1, 2e6, 1);
    }


    int q; cin >> q;

    while(q--){
        int i, x,y; cin >> i >> x >> y;

        int p = max(a[i] - A, 0) + max(b[i] - B, 0);
        update(1,0,2e6, p+1, 2e6, -1);

        a[i] = x;
        b[i] = y;

        p = max(a[i] - A, 0) + max(b[i] - B, 0);
        update(1,0,2e6, p+1, 2e6, 1);

        cout << query(1, 0, 2e6, 1, 2e6)-1 << "\n";

    }




 }