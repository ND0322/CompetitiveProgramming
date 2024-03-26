#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2e5+5;

#define int long long

int n, q;

struct Node{
    long long sum, mn, lz;
} st[MAXN<<2];

void pushdown(int node, int l, int r){
    if(!st[node].lz || l == r) return;
    int mid = (l+r)>>1;

    st[node<<1].lz += st[node].lz;
    st[node<<1|1].lz += st[node].lz;
    st[node<<1].sum += (mid-l+1) * st[node].lz;
    st[node<<1|1].sum += (r-mid) * st[node].lz;
    st[node<<1].mn += st[node].lz;
    st[node<<1|1].mn += st[node].lz;
    st[node].lz = 0;
}

void build(int node, int l, int r){
    st[node].lz = 0;

    if(l == r){
        cin >> st[node].sum;
        st[node].mn = st[node].sum;
        return;
    }

    int mid = (l+r)>>1;
    build(node<<1, l, mid);
    build(node<<1|1, mid+1, r);
    st[node].sum = st[node<<1].sum + st[node<<1|1].sum;
    st[node].mn = min(st[node<<1].mn, st[node<<1|1].mn);
}

void update(int node, int l, int r, int x, int y, int val){
    if(x > r || y < l) return;

    if(x <= l && y >= r){
        st[node].sum += (r-l+1) * val;
        st[node].mn += val;
        st[node].lz += val;
        return;
    }

    int mid = (l+r)>>1;
    pushdown(node, l, r);
    update(node<<1, l, mid, x, y, val);
    update(node<<1|1, mid+1, r, x, y ,val);
    st[node].sum = st[node<<1].sum + st[node<<1|1].sum;
    st[node].mn = min(st[node<<1].mn, st[node<<1|1].mn);

}

long long query(int node, int l, int r, int x, int y){
    if(x > r || y < l) return 1e18;
    if(x <= l && y >= r) return st[node].mn;

    int mid = (l+r)>>1;
    pushdown(node, l, r);
    return min(query(node<<1, l, mid, x, y),query(node<<1|1, mid+1, r, x , y));
}

long long querys(int node, int l, int r, int x, int y){

    if(x > r || y < l) return 0;
    if(x <= l && y >= r) return st[node].sum;
    
    
    int mid = (l+r)>>1;
    pushdown(node, l, r);
    return querys(node<<1, l, mid, x, y) + querys(node<<1|1, mid+1, r, x , y);
}

int32_t main(){
    freopen("haybales.in", "r", stdin);
    freopen("haybales.out", "w", stdout);
    cin >> n >> q;

    build(1,1,n);

    while(q--){
        char act; cin >> act;

        if(act == 'M'){
            int l,r; cin >> l >> r;
            cout << query(1,1,n,l,r) << "\n";
        }
        if(act == 'S'){
            int l, r; cin >> l >> r;
            cout << querys(1,1,n,l,r) << "\n";
        }
        if(act == 'P'){
            int l,r,c; cin >> l >> r >> c;
            update(1,1,n,l,r,c);
        }
    }
}