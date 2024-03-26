#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define int long long

const int MAXN = 1e6+5;

int n, q;

//probably an observation based solution but lazy seg so

struct Node{
    int mn, lz;
} st[MAXN<<2];

void pushdown(int node){
    if(!st[node].lz) return;

    st[node<<1].lz += st[node].lz;
    st[node<<1|1].lz += st[node].lz;
    st[node<<1].mn += st[node].lz;
    st[node<<1|1].mn += st[node].lz;
    st[node].lz = 0;
}

void build(int node, int l, int r){
    st[node].lz = 0;

    if(l == r){
        cin >> st[node].mn;
        return;
    }

    int mid = (l+r)>>1;

    build(node<<1,l,mid);
    build(node<<1|1,mid+1,r);
    st[node].mn = min(st[node<<1].mn, st[node<<1|1].mn);
}

void update(int node, int l, int r, int x, int y, int val){
    if(x > r || y < l) return;
    if(x <= l && y >= r){
        st[node].mn -= val;
        st[node].lz -= val;
        return;
    }

    int mid = (l+r)>>1;
    pushdown(node);
    update(node<<1,l,mid,x,y,val);
    update(node<<1|1, mid+1,r,x,y,val);
    st[node].mn = min(st[node<<1].mn, st[node<<1|1].mn);
}

int query(int node, int l, int r, int x, int y){
    if(x > r || y < l) return 1e9;
    if(x <= l && y >= r) return st[node].mn;

    int mid = (l+r)>>1;
    pushdown(node);
    return min(query(node<<1,l,mid,x,y), query(node<<1|1,mid+1,r,x,y));
}

int32_t main(){
    cin >> n >> q;

    build(1,1,n);

    while(q--){
        int l,r,x; cin >> l >> r >> x;

        update(1,1,n,l,r,x);
        cout << max(query(1,1,n,l,r),0LL) << " " << max(st[1].mn,0LL) << "\n";
    }
}